


  # labwork.S
  # Written 2015 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1 2015-2016.
  # The macros PUSH and POP are in the public domain.
.global delay
.global time2string
.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
.data
.align 2
.text

main:
  # You can add your own code here

  # you can write your code for subroutine "hexasc" and  below this line
hexasc:
   	andi	$a0,$a0,0xf		#only 4 least significant bits ignore(clear) other bits	
   	addi	$v0,$zero,0x30	#$v0 = 0x30 ('0' ASCII character)
   	addi	$t0,$zero,0x9	#t0 = 0x9
   	
   	ble	$a0,$t0,L1		#branch to L1 if a0 <= t0
   	nop
   	addi	$v0,$v0,0x7		#v0 = v0 +0x7 (thier is 7 other characters from 0x39 to 0x41) thats why 
					#0x7 is added to the v0 to ignore the gap and jump directly to 'A' in ASCII table
   	
   L1:
   	add	$v0,$a0,$v0 	#v0 = V0 +a0 
   	jr	$ra
   	nop


delay:
	PUSH	$s0
	PUSH	$ra
	addi	$s0, $0,1000	#i = 0
	addi	$t1,$0,30000   	#(intitaly was t1=4711)
	move	$t0,$a0		#move the argument to t0
while:
	ble	$t0,$s0,done	#branch to done if ms > 0
	nop
	addi	$t0,$t0,-1		#decrement ms by 1	
for:
	beq	$s0,$t1,done2
	nop
	addi	$s0,$s0,1
	j	for
done2:	
	
	j	while
done:	
	POP	$ra
	POP	$s0
 	jr	$ra
 	nop

	
 	
 time2string:
 	PUSH	$s0			
 	PUSH	$s1
 	PUSH	$ra			#nested subroutine must store $ra too
 	
 	add	$s0,$0,$a0		#contains the adress of string (timstr)
 	add	$s1,$0,$a1		#contains the time-info(0x5957)
 	
 	andi	$t0,$s1,0xf000  	#check the 4 most signifaicant bits ignore(clear) other bits
 	srl	$a0,$t0,12		#shift the MSB to LSB position (hexasc take only 4 bits in the LSB position)
 	jal	hexasc		# call hexasc
 	nop		
 	sb	$v0, 0($s0)		#stor that 4 bits in that location that a0 points to
 	
 	andi	$t1,$s1,0x0f00	#mask to get those 4 bits you need and ignore other bits
 	srl	$a0,$t1,8		#shift those bits to the LSB position(0x000f)
 	jal	hexasc		#this is becouse hexasc only take argument on the LSB postion and clear other bits.
 	nop
 	sb	$v0,1($s0)		#store this bits in that address pointed by a0 
 	
 	li	$t3,0x3A		#t3 = a colon in ASCII table 
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
 	
 	
 	li	$t4,0x00		# a null \0 in ASCII table
 	sb	$t4,5($s0)
 	
 
 	POP	$ra
 	POP	$s1	
 	POP	$s0
 	
 	jr	$ra
 	nop	