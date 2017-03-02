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
	li	$a0,30000
	jal	delay
	nop
	# call tick
	la	$a0,mytime
	jal	tick
	nop
	# call your function time2string
	la	$a0,timstr
	la	$t0,mytime
	lw	$a1,0($t0) 	#load the adress contained in $t0 into $a1
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
   	andi	$a0,$a0,0xf		#only 4 least significant bits ignore(clear) other bits	
   	addi	$v0,$zero,0x30	        #$v0 = 0x30 ('0' ASCII character)
   	addi	$t0,$zero,0x9	        #t0 = 0x9
   	
   	ble	$a0,$t0,L1		#branch to L1 if a0 <= t0
   	nop
   	addi	$v0,$v0,0x7		#v0 = v0 +0x7 (thier is 7 other characters from 0x39 to 0x41) thats why 
					# 0x7 is added to the v0 to ignore the gap and print firectly A
   	
   L1:
   	add	$v0,$a0,$v0 	#v0 = V0 +a0 (if 
   	jr	$ra
   	nop


delay:
	PUSH	($s0)
	PUSH	($ra)
	addi	$s0, $0,0		#i = 0
	addi	$t1,$0,4711
	move	$t0,$a0		#move the argument to t0
while:
	bgt	$t0,$s0,done	#branch to done if ms > 0
	addi	$t0,$t0,-1		#decrement ms by 1	
for:
	beq	$s0,$t1,done
	addi	$s0,$s0,1
	j	for
	
	
	j	while
done:	
	POP	($ra)
	POP	($s0)
 	jr	$ra
 	nop

	
 	
 time2string:
 	PUSH	($s0)			
 	PUSH	($s1)
 	PUSH	($ra)			#nested subroutine must store $ra too
 	
 	add	$s0,$0,$a0		#contaisn the adress of string (timstr)
 	add	$s1,$0,$a1		#contains the time-info(0x5957)
 	
 	andi	$t0,$s1,0xf000  	#check the 4 most signifaicant bits ignore other bits
 	srl	$a0,$t0,12		#shift the MSB to LSB position (hexasc take only 4 bits in the LSB position)
 	jal	hexasc		# call hexasc
 	nop		
 	sb	$v0, 0($s0)		#stor that 4 bits in that location that a0 points to
 	
 	andi	$t1,$s1,0x0f00	#mask to get those 4 bits you and ignore other bits
 	srl	$a0,$t1,8		#shift those bits to the LSB position(0x000f)
 	jal	hexasc		#this is becouse hexasc only take argument on the LSB postion and clear other bits.
 	nop
 	sb	$v0,1($s0)		
 	
 	li	$t3,0x3A
 	sb	$t3,2($s0)
 	
 	
 	andi	$t2,$s1,0x00f0
 	srl	$a0,$t2,4
 	jal	hexasc
 	nop
 	sb	$v0,3($s0)
 	
 	
 	move	$a0,$s1
 	jal	hexasc
 	nop
 	sb	$v0, 4($s0)
 	
 	
 	li	$t4,0x00
 	sb	$t4,5($s0)
 	
 
 	POP	($ra)
 	POP	($s1)	
 	POP	($s0)
 	
 	jr	$ra
 	nop	
