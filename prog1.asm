add $3, $2, $0
sub $0, $31, $22
beq	$1, $2, 0x200
beq	$1, $2, 0x1e00
j	0x40000
add	$3, $4, $8
addi	$2, $1, 100
sub	$2, $3, $9
slt	$1, $2, $10
slt	$1, $2, $3
lw	$1, 700($2)
sw      $17, 500($4)
	
