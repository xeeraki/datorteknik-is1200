  # hexmain.asm
  # Written 2015-09-04 by F Lundevall
  # Copyright abandonded - this file is in the public domain.
	.text
main:
	li	$a0,4		# change this to test different values

	jal	hexasc		# call hexasc
	nop			# delay slot filler (just in case)	

	move	$a0,$v0		# copy return value to argument register

	li	$v0,11		# syscall with v0 = 11 will print out
	syscall			# one byte from a0 to the Run I/O window
	
stop:	j	stop		# stop after one run
	nop			# delay slot filler (just in case)

  # You can write your own code for hexasc here
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
