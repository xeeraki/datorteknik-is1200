  # timetemplate.asm
  # Written 2015 by F Lundevall
  # Copyright abandonded - this file is in the public domain.

.macro	PUSH (%reg)
	addi	$sp,$sp,-4
	sw	%reg,0($sp)
.end_macro

.macro	POP (%reg)
	lw	%reg,0($sp)
	addi	$sp,$sp,4
.end_macro

	.data
	.align 2
mytime:	.word 0x5957
timstr:	.ascii "text more text lots of text\0"
	.text
main:
	# print timstr
	la	$a0,timstr
	li	$v0,4
	syscall
	nop
	# wait a little
	li	$a0,2
	jal	delay
	nop
	# call tick
	la	$a0,mytime
	jal	tick
	nop
	# call your function time2string
	la	$a0,timstr
	la	$t0,mytime
	lw	$a1,0($t0) #load the adress contained in $t0 into $a1
	jal	time2string
	nop
	# print a newline
	li	$a0,10
	li	$v0,11
	syscall
	nop
	# go back and do it all again
	j	main
	nop
# tick: update time pointed to by $a0
tick:	lw	$t0,0($a0)	# get time
	addiu	$t0,$t0,1	# increase
	andi	$t1,$t0,0xf	# check lowest digit
	sltiu	$t2,$t1,0xa	# if digit < a, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0x6		# adjust lowest digit
	andi	$t1,$t0,0xf0	# check next digit
	sltiu	$t2,$t1,0x60	# if digit < 6, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0xa0	# adjust digit
	andi	$t1,$t0,0xf00	# check minute digit
	sltiu	$t2,$t1,0xa00	# if digit < a, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0x600	# adjust digit
	andi	$t1,$t0,0xf000	# check last digit
	sltiu	$t2,$t1,0x6000	# if digit < 6, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0xa000	# adjust last digit
tiend:	sw	$t0,0($a0)	# save updated result
	jr	$ra			# return
	nop

  # you can write your code for subroutine "hexasc" and  below this line
  #
hexasc:
   	andi	$a0,$a0,0xf		#only 4 least significant bits ignore other bits	
   	addi	$v0,$zero,0x30	#$v0 = 0x30 ('0')
   	addi	$t0,$zero,0x9	#t0 = 0x9
   	
   	ble	$a0,$t0,L1		#branch if a0 <= 0x9
   	nop
   	addi	$v0,$v0,0x7		#v0 = v0 +0x7
   	
   L1:
   	add	$v0,$a0,$v0 	#v0 = V0 +a0
   	jr	$ra
   	nop


delay:
 	jr	$ra
 	nop

	
 	
 time2string:
 	PUSH	($t0)			
 	PUSH	($t1)
 	PUSH	($t2)
 	PUSH	($t3)
 	PUSH	($t4)
 	PUSH	($t5)
 	PUSH	($ra)			#nested subroutine must store $ra too
 	
 	add	$t0,$0,$a0		#contaisn the adress of string (timstr)
 	add	$t1,$0,$a1		#contains the time-info(0x5957)
 	
 	andi	$t2,$t1,0xf000  	#check the 4 most signifaicant bits ignore other bits
 	srl	$a0,$t2,12		#shift the MSB to LSB position (hexasc take only 4 bits in the LSB position)
 	jal	hexasc		# call hexasc
 	nop		
 	sb	$v0, 0($t0)		#stor that 4 bits in that location that a0 points to
 	
 	andi	$t3,$t1,0x0f00	#mask to get those 4 bits you and ignore other bits
 	srl	$a0,$t3,8		#shift those bits to the LSB position(0x000f)
 	jal	hexasc		
 	nop
 	sb	$v0,1($t0)		
 	
 	li	$t5,0x3A
 	sb	$t5,2($t0)
 	
 	
 	andi	$t4,$t1,0x00f0
 	srl	$a0,$t4,4
 	jal	hexasc
 	nop
 	sb	$v0,3($t0)
 	
 	
 	move	$a0,$t1
 	jal	hexasc
 	nop
 	sb	$v0, 4($t0)
 	
 	
 	li	$t6,0x00
 	sb	$t6,5($t0)
 	
 
 	POP	($ra)
 	POP	($t5)
 	POP	($t4)
 	POP	($t3)
 	POP	($t2)
 	POP	($t1)	
 	POP	($t0)
 	
 	jr	$ra
 	nop	
