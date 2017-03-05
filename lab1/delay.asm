#Written by Adam Shafai
#Converted from The C counterpart from KTH IS1200 lab 1.
delay:
	PUSH	($s0)
	PUSH	($ra)
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
	POP	($ra)
	POP	($s0)
 	jr	$ra
 	nop

