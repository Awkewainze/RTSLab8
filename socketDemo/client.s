	.file	"client.c"
	.text
.Ltext0:
	.globl	error
	.type	error, @function
error:
.LFB2:
	.file 1 "client.c"
	.loc 1 14 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	.loc 1 16 0
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	perror
	.loc 1 18 0
	movl	$-1, %edi
	call	exit
	.cfi_endproc
.LFE2:
	.size	error, .-error
	.section	.rodata
.LC0:
	.string	"usage %s hostname port\n"
.LC1:
	.string	"ERROR opening socket"
.LC2:
	.string	"ERROR, no such host\n"
.LC3:
	.string	"ERROR connecting"
.LC4:
	.string	"Please enter the message: "
.LC5:
	.string	"ERROR writing to socket"
.LC6:
	.string	"ERROR reading from socket"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.loc 1 29 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$344, %rsp
	.cfi_offset 3, -24
	movl	%edi, -340(%rbp)
	movq	%rsi, -352(%rbp)
	.loc 1 29 0
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	.loc 1 35 0
	cmpl	$2, -340(%rbp)
	jg	.L3
	.loc 1 36 0
	movq	-352(%rbp), %rax
	movq	(%rax), %rdx
	movq	stderr(%rip), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	.loc 1 37 0
	movl	$0, %edi
	call	exit
.L3:
	.loc 1 41 0
	movq	-352(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -324(%rbp)
	.loc 1 44 0
	movl	$0, %edx
	movl	$1, %esi
	movl	$2, %edi
	call	socket
	movl	%eax, -320(%rbp)
	.loc 1 48 0
	cmpl	$0, -320(%rbp)
	jns	.L4
	.loc 1 50 0
	movl	$.LC1, %edi
	call	error
.L4:
	.loc 1 54 0
	movq	-352(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	gethostbyname
	movq	%rax, -312(%rbp)
	.loc 1 57 0
	cmpq	$0, -312(%rbp)
	jne	.L5
	.loc 1 58 0
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$20, %edx
	movl	$1, %esi
	movl	$.LC2, %edi
	call	fwrite
	.loc 1 59 0
	movl	$0, %edi
	call	exit
.L5:
	.loc 1 63 0
	leaq	-304(%rbp), %rax
	movl	$16, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset
	.loc 1 66 0
	movw	$2, -304(%rbp)
	.loc 1 69 0
	movq	-312(%rbp), %rax
	movl	20(%rax), %eax
	movslq	%eax, %rdx
	movq	-312(%rbp), %rax
	movq	24(%rax), %rax
	movq	(%rax), %rax
	leaq	-304(%rbp), %rcx
	addq	$4, %rcx
	movq	%rax, %rsi
	movq	%rcx, %rdi
	call	memcpy
	.loc 1 72 0
	movl	-324(%rbp), %eax
	movzwl	%ax, %eax
	movl	%eax, %edi
	call	htons
	movw	%ax, -302(%rbp)
	.loc 1 75 0
	leaq	-304(%rbp), %rcx
	movl	-320(%rbp), %eax
	movl	$16, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	connect
	testl	%eax, %eax
	jns	.L6
	.loc 1 77 0
	movl	$.LC3, %edi
	call	error
.L6:
	.loc 1 80 0
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	.loc 1 83 0
	leaq	-288(%rbp), %rax
	movl	$256, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset
	.loc 1 86 0
	movq	stdin(%rip), %rdx
	leaq	-288(%rbp), %rax
	movl	$255, %esi
	movq	%rax, %rdi
	call	fgets
	.loc 1 89 0
	leaq	-288(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	movq	%rax, %rdx
	leaq	-288(%rbp), %rcx
	movl	-320(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	movl	$0, %eax
	call	write
	movl	%eax, -316(%rbp)
	.loc 1 92 0
	cmpl	$0, -316(%rbp)
	jns	.L7
	.loc 1 94 0
	movl	$.LC5, %edi
	call	error
.L7:
	.loc 1 98 0
	leaq	-288(%rbp), %rax
	movl	$256, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset
	.loc 1 101 0
	leaq	-288(%rbp), %rcx
	movl	-320(%rbp), %eax
	movl	$255, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	movl	$0, %eax
	call	read
	movl	%eax, -316(%rbp)
	.loc 1 104 0
	cmpl	$0, -316(%rbp)
	jns	.L8
	.loc 1 106 0
	movl	$.LC6, %edi
	call	error
.L8:
	.loc 1 110 0
	leaq	-288(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	.loc 1 113 0
	leaq	-288(%rbp), %rax
	movl	$256, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset
	.loc 1 116 0
	leaq	-288(%rbp), %rcx
	movl	-320(%rbp), %eax
	movl	$255, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	movl	$0, %eax
	call	read
	movl	%eax, -316(%rbp)
	.loc 1 119 0
	cmpl	$0, -316(%rbp)
	jns	.L9
	.loc 1 121 0
	movl	$.LC6, %edi
	call	error
.L9:
	.loc 1 125 0
	leaq	-288(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	.loc 1 127 0
	movl	$0, %eax
	.loc 1 128 0
	movq	-24(%rbp), %rbx
	xorq	%fs:40, %rbx
	je	.L11
	call	__stack_chk_fail
.L11:
	addq	$344, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
.Letext0:
	.file 2 "/usr/lib/gcc/x86_64-linux-gnu/4.8/include/stddef.h"
	.file 3 "/usr/include/x86_64-linux-gnu/bits/types.h"
	.file 4 "/usr/include/libio.h"
	.file 5 "/usr/include/x86_64-linux-gnu/bits/sockaddr.h"
	.file 6 "/usr/include/x86_64-linux-gnu/bits/socket.h"
	.file 7 "/usr/include/stdint.h"
	.file 8 "/usr/include/netinet/in.h"
	.file 9 "/usr/include/netdb.h"
	.file 10 "/usr/include/stdio.h"
	.file 11 "/usr/include/x86_64-linux-gnu/bits/socket_type.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x506
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF87
	.byte	0x1
	.long	.LASF88
	.long	.LASF89
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF7
	.byte	0x2
	.byte	0xd4
	.long	0x38
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF0
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.long	.LASF1
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.long	.LASF2
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF3
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.long	.LASF5
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF6
	.uleb128 0x2
	.long	.LASF8
	.byte	0x3
	.byte	0x83
	.long	0x69
	.uleb128 0x2
	.long	.LASF9
	.byte	0x3
	.byte	0x84
	.long	0x69
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF10
	.uleb128 0x5
	.byte	0x8
	.uleb128 0x6
	.byte	0x8
	.long	0x95
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF11
	.uleb128 0x7
	.long	.LASF41
	.byte	0xd8
	.byte	0x4
	.byte	0xf5
	.long	0x21c
	.uleb128 0x8
	.long	.LASF12
	.byte	0x4
	.byte	0xf6
	.long	0x62
	.byte	0
	.uleb128 0x8
	.long	.LASF13
	.byte	0x4
	.byte	0xfb
	.long	0x8f
	.byte	0x8
	.uleb128 0x8
	.long	.LASF14
	.byte	0x4
	.byte	0xfc
	.long	0x8f
	.byte	0x10
	.uleb128 0x8
	.long	.LASF15
	.byte	0x4
	.byte	0xfd
	.long	0x8f
	.byte	0x18
	.uleb128 0x8
	.long	.LASF16
	.byte	0x4
	.byte	0xfe
	.long	0x8f
	.byte	0x20
	.uleb128 0x8
	.long	.LASF17
	.byte	0x4
	.byte	0xff
	.long	0x8f
	.byte	0x28
	.uleb128 0x9
	.long	.LASF18
	.byte	0x4
	.value	0x100
	.long	0x8f
	.byte	0x30
	.uleb128 0x9
	.long	.LASF19
	.byte	0x4
	.value	0x101
	.long	0x8f
	.byte	0x38
	.uleb128 0x9
	.long	.LASF20
	.byte	0x4
	.value	0x102
	.long	0x8f
	.byte	0x40
	.uleb128 0x9
	.long	.LASF21
	.byte	0x4
	.value	0x104
	.long	0x8f
	.byte	0x48
	.uleb128 0x9
	.long	.LASF22
	.byte	0x4
	.value	0x105
	.long	0x8f
	.byte	0x50
	.uleb128 0x9
	.long	.LASF23
	.byte	0x4
	.value	0x106
	.long	0x8f
	.byte	0x58
	.uleb128 0x9
	.long	.LASF24
	.byte	0x4
	.value	0x108
	.long	0x254
	.byte	0x60
	.uleb128 0x9
	.long	.LASF25
	.byte	0x4
	.value	0x10a
	.long	0x25a
	.byte	0x68
	.uleb128 0x9
	.long	.LASF26
	.byte	0x4
	.value	0x10c
	.long	0x62
	.byte	0x70
	.uleb128 0x9
	.long	.LASF27
	.byte	0x4
	.value	0x110
	.long	0x62
	.byte	0x74
	.uleb128 0x9
	.long	.LASF28
	.byte	0x4
	.value	0x112
	.long	0x70
	.byte	0x78
	.uleb128 0x9
	.long	.LASF29
	.byte	0x4
	.value	0x116
	.long	0x46
	.byte	0x80
	.uleb128 0x9
	.long	.LASF30
	.byte	0x4
	.value	0x117
	.long	0x54
	.byte	0x82
	.uleb128 0x9
	.long	.LASF31
	.byte	0x4
	.value	0x118
	.long	0x260
	.byte	0x83
	.uleb128 0x9
	.long	.LASF32
	.byte	0x4
	.value	0x11c
	.long	0x270
	.byte	0x88
	.uleb128 0x9
	.long	.LASF33
	.byte	0x4
	.value	0x125
	.long	0x7b
	.byte	0x90
	.uleb128 0x9
	.long	.LASF34
	.byte	0x4
	.value	0x12e
	.long	0x8d
	.byte	0x98
	.uleb128 0x9
	.long	.LASF35
	.byte	0x4
	.value	0x12f
	.long	0x8d
	.byte	0xa0
	.uleb128 0x9
	.long	.LASF36
	.byte	0x4
	.value	0x130
	.long	0x8d
	.byte	0xa8
	.uleb128 0x9
	.long	.LASF37
	.byte	0x4
	.value	0x131
	.long	0x8d
	.byte	0xb0
	.uleb128 0x9
	.long	.LASF38
	.byte	0x4
	.value	0x132
	.long	0x2d
	.byte	0xb8
	.uleb128 0x9
	.long	.LASF39
	.byte	0x4
	.value	0x134
	.long	0x62
	.byte	0xc0
	.uleb128 0x9
	.long	.LASF40
	.byte	0x4
	.value	0x136
	.long	0x276
	.byte	0xc4
	.byte	0
	.uleb128 0xa
	.long	.LASF90
	.byte	0x4
	.byte	0x9a
	.uleb128 0x7
	.long	.LASF42
	.byte	0x18
	.byte	0x4
	.byte	0xa0
	.long	0x254
	.uleb128 0x8
	.long	.LASF43
	.byte	0x4
	.byte	0xa1
	.long	0x254
	.byte	0
	.uleb128 0x8
	.long	.LASF44
	.byte	0x4
	.byte	0xa2
	.long	0x25a
	.byte	0x8
	.uleb128 0x8
	.long	.LASF45
	.byte	0x4
	.byte	0xa6
	.long	0x62
	.byte	0x10
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x223
	.uleb128 0x6
	.byte	0x8
	.long	0x9c
	.uleb128 0xb
	.long	0x95
	.long	0x270
	.uleb128 0xc
	.long	0x86
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x21c
	.uleb128 0xb
	.long	0x95
	.long	0x286
	.uleb128 0xc
	.long	0x86
	.byte	0x13
	.byte	0
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF46
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF47
	.uleb128 0xd
	.long	.LASF91
	.byte	0x4
	.byte	0xb
	.byte	0x18
	.long	0x2da
	.uleb128 0xe
	.long	.LASF48
	.sleb128 1
	.uleb128 0xe
	.long	.LASF49
	.sleb128 2
	.uleb128 0xe
	.long	.LASF50
	.sleb128 3
	.uleb128 0xe
	.long	.LASF51
	.sleb128 4
	.uleb128 0xe
	.long	.LASF52
	.sleb128 5
	.uleb128 0xe
	.long	.LASF53
	.sleb128 6
	.uleb128 0xe
	.long	.LASF54
	.sleb128 10
	.uleb128 0xe
	.long	.LASF55
	.sleb128 524288
	.uleb128 0xe
	.long	.LASF56
	.sleb128 2048
	.byte	0
	.uleb128 0x2
	.long	.LASF57
	.byte	0x5
	.byte	0x1c
	.long	0x46
	.uleb128 0x7
	.long	.LASF58
	.byte	0x10
	.byte	0x6
	.byte	0x95
	.long	0x30a
	.uleb128 0x8
	.long	.LASF59
	.byte	0x6
	.byte	0x97
	.long	0x2da
	.byte	0
	.uleb128 0x8
	.long	.LASF60
	.byte	0x6
	.byte	0x98
	.long	0x30a
	.byte	0x2
	.byte	0
	.uleb128 0xb
	.long	0x95
	.long	0x31a
	.uleb128 0xc
	.long	0x86
	.byte	0xd
	.byte	0
	.uleb128 0x2
	.long	.LASF61
	.byte	0x7
	.byte	0x31
	.long	0x46
	.uleb128 0x2
	.long	.LASF62
	.byte	0x7
	.byte	0x33
	.long	0x4d
	.uleb128 0x2
	.long	.LASF63
	.byte	0x8
	.byte	0x1e
	.long	0x325
	.uleb128 0x7
	.long	.LASF64
	.byte	0x4
	.byte	0x8
	.byte	0x1f
	.long	0x354
	.uleb128 0x8
	.long	.LASF65
	.byte	0x8
	.byte	0x21
	.long	0x330
	.byte	0
	.byte	0
	.uleb128 0x2
	.long	.LASF66
	.byte	0x8
	.byte	0x75
	.long	0x31a
	.uleb128 0x7
	.long	.LASF67
	.byte	0x10
	.byte	0x8
	.byte	0xed
	.long	0x39c
	.uleb128 0x8
	.long	.LASF68
	.byte	0x8
	.byte	0xef
	.long	0x2da
	.byte	0
	.uleb128 0x8
	.long	.LASF69
	.byte	0x8
	.byte	0xf0
	.long	0x354
	.byte	0x2
	.uleb128 0x8
	.long	.LASF70
	.byte	0x8
	.byte	0xf1
	.long	0x33b
	.byte	0x4
	.uleb128 0x8
	.long	.LASF71
	.byte	0x8
	.byte	0xf4
	.long	0x39c
	.byte	0x8
	.byte	0
	.uleb128 0xb
	.long	0x3f
	.long	0x3ac
	.uleb128 0xc
	.long	0x86
	.byte	0x7
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x8f
	.uleb128 0x7
	.long	.LASF72
	.byte	0x20
	.byte	0x9
	.byte	0x64
	.long	0x3fb
	.uleb128 0x8
	.long	.LASF73
	.byte	0x9
	.byte	0x66
	.long	0x8f
	.byte	0
	.uleb128 0x8
	.long	.LASF74
	.byte	0x9
	.byte	0x67
	.long	0x3ac
	.byte	0x8
	.uleb128 0x8
	.long	.LASF75
	.byte	0x9
	.byte	0x68
	.long	0x62
	.byte	0x10
	.uleb128 0x8
	.long	.LASF76
	.byte	0x9
	.byte	0x69
	.long	0x62
	.byte	0x14
	.uleb128 0x8
	.long	.LASF77
	.byte	0x9
	.byte	0x6a
	.long	0x3ac
	.byte	0x18
	.byte	0
	.uleb128 0xf
	.long	.LASF92
	.byte	0x1
	.byte	0xd
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x427
	.uleb128 0x10
	.string	"msg"
	.byte	0x1
	.byte	0xd
	.long	0x8f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x11
	.long	.LASF93
	.byte	0x1
	.byte	0x1c
	.long	0x62
	.quad	.LFB3
	.quad	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.long	0x4dd
	.uleb128 0x12
	.long	.LASF78
	.byte	0x1
	.byte	0x1c
	.long	0x62
	.uleb128 0x3
	.byte	0x91
	.sleb128 -356
	.uleb128 0x12
	.long	.LASF79
	.byte	0x1
	.byte	0x1c
	.long	0x3ac
	.uleb128 0x3
	.byte	0x91
	.sleb128 -368
	.uleb128 0x13
	.long	.LASF80
	.byte	0x1
	.byte	0x1e
	.long	0x62
	.uleb128 0x3
	.byte	0x91
	.sleb128 -336
	.uleb128 0x13
	.long	.LASF81
	.byte	0x1
	.byte	0x1e
	.long	0x62
	.uleb128 0x3
	.byte	0x91
	.sleb128 -340
	.uleb128 0x14
	.string	"n"
	.byte	0x1
	.byte	0x1e
	.long	0x62
	.uleb128 0x3
	.byte	0x91
	.sleb128 -332
	.uleb128 0x13
	.long	.LASF82
	.byte	0x1
	.byte	0x1f
	.long	0x35f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -320
	.uleb128 0x13
	.long	.LASF83
	.byte	0x1
	.byte	0x20
	.long	0x4dd
	.uleb128 0x3
	.byte	0x91
	.sleb128 -328
	.uleb128 0x13
	.long	.LASF84
	.byte	0x1
	.byte	0x22
	.long	0x4e3
	.uleb128 0x3
	.byte	0x91
	.sleb128 -304
	.uleb128 0x15
	.long	.LASF94
	.byte	0x1
	.byte	0x59
	.long	0x62
	.long	0x4cf
	.uleb128 0x16
	.byte	0
	.uleb128 0x17
	.long	.LASF95
	.byte	0x1
	.byte	0x65
	.long	0x62
	.uleb128 0x16
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x3b2
	.uleb128 0xb
	.long	0x95
	.long	0x4f3
	.uleb128 0xc
	.long	0x86
	.byte	0xff
	.byte	0
	.uleb128 0x18
	.long	.LASF85
	.byte	0xa
	.byte	0xa8
	.long	0x25a
	.uleb128 0x18
	.long	.LASF86
	.byte	0xa
	.byte	0xaa
	.long	0x25a
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xd
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF94:
	.string	"write"
.LASF41:
	.string	"_IO_FILE"
.LASF53:
	.string	"SOCK_DCCP"
.LASF23:
	.string	"_IO_save_end"
.LASF95:
	.string	"read"
.LASF5:
	.string	"short int"
.LASF7:
	.string	"size_t"
.LASF10:
	.string	"sizetype"
.LASF33:
	.string	"_offset"
.LASF17:
	.string	"_IO_write_ptr"
.LASF12:
	.string	"_flags"
.LASF19:
	.string	"_IO_buf_base"
.LASF91:
	.string	"__socket_type"
.LASF72:
	.string	"hostent"
.LASF24:
	.string	"_markers"
.LASF14:
	.string	"_IO_read_end"
.LASF54:
	.string	"SOCK_PACKET"
.LASF83:
	.string	"server"
.LASF68:
	.string	"sin_family"
.LASF77:
	.string	"h_addr_list"
.LASF79:
	.string	"argv"
.LASF86:
	.string	"stderr"
.LASF47:
	.string	"long long int"
.LASF32:
	.string	"_lock"
.LASF80:
	.string	"sockfd"
.LASF6:
	.string	"long int"
.LASF49:
	.string	"SOCK_DGRAM"
.LASF29:
	.string	"_cur_column"
.LASF81:
	.string	"portno"
.LASF45:
	.string	"_pos"
.LASF70:
	.string	"sin_addr"
.LASF44:
	.string	"_sbuf"
.LASF28:
	.string	"_old_offset"
.LASF74:
	.string	"h_aliases"
.LASF57:
	.string	"sa_family_t"
.LASF1:
	.string	"unsigned char"
.LASF51:
	.string	"SOCK_RDM"
.LASF78:
	.string	"argc"
.LASF89:
	.string	"/home/dylan/Documents/rts_labs/RTSLab8/socketDemo"
.LASF38:
	.string	"__pad5"
.LASF4:
	.string	"signed char"
.LASF71:
	.string	"sin_zero"
.LASF46:
	.string	"long long unsigned int"
.LASF82:
	.string	"serv_addr"
.LASF62:
	.string	"uint32_t"
.LASF3:
	.string	"unsigned int"
.LASF42:
	.string	"_IO_marker"
.LASF31:
	.string	"_shortbuf"
.LASF65:
	.string	"s_addr"
.LASF0:
	.string	"long unsigned int"
.LASF9:
	.string	"__off64_t"
.LASF16:
	.string	"_IO_write_base"
.LASF36:
	.string	"__pad3"
.LASF13:
	.string	"_IO_read_ptr"
.LASF60:
	.string	"sa_data"
.LASF20:
	.string	"_IO_buf_end"
.LASF52:
	.string	"SOCK_SEQPACKET"
.LASF11:
	.string	"char"
.LASF61:
	.string	"uint16_t"
.LASF93:
	.string	"main"
.LASF43:
	.string	"_next"
.LASF34:
	.string	"__pad1"
.LASF35:
	.string	"__pad2"
.LASF87:
	.string	"GNU C 4.8.4 -mtune=generic -march=x86-64 -g -fstack-protector"
.LASF37:
	.string	"__pad4"
.LASF63:
	.string	"in_addr_t"
.LASF73:
	.string	"h_name"
.LASF84:
	.string	"buffer"
.LASF50:
	.string	"SOCK_RAW"
.LASF55:
	.string	"SOCK_CLOEXEC"
.LASF75:
	.string	"h_addrtype"
.LASF88:
	.string	"client.c"
.LASF64:
	.string	"in_addr"
.LASF18:
	.string	"_IO_write_end"
.LASF76:
	.string	"h_length"
.LASF26:
	.string	"_fileno"
.LASF2:
	.string	"short unsigned int"
.LASF25:
	.string	"_chain"
.LASF69:
	.string	"sin_port"
.LASF8:
	.string	"__off_t"
.LASF22:
	.string	"_IO_backup_base"
.LASF85:
	.string	"stdin"
.LASF66:
	.string	"in_port_t"
.LASF27:
	.string	"_flags2"
.LASF59:
	.string	"sa_family"
.LASF39:
	.string	"_mode"
.LASF15:
	.string	"_IO_read_base"
.LASF30:
	.string	"_vtable_offset"
.LASF40:
	.string	"_unused2"
.LASF92:
	.string	"error"
.LASF21:
	.string	"_IO_save_base"
.LASF67:
	.string	"sockaddr_in"
.LASF48:
	.string	"SOCK_STREAM"
.LASF58:
	.string	"sockaddr"
.LASF90:
	.string	"_IO_lock_t"
.LASF56:
	.string	"SOCK_NONBLOCK"
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
