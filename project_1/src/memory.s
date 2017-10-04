	.file	"memory.c"
	.text
.Ltext0:
	.globl	my_memmove
	.type	my_memmove, @function
my_memmove:
.LFB0:
	.file 1 "memory.c"
	.loc 1 18 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	.loc 1 20 0
	movq	-24(%rbp), %rax
	cmpq	-32(%rbp), %rax
	jne	.L2
	.loc 1 21 0
	movq	-32(%rbp), %rax
	jmp	.L3
.L2:
	.loc 1 22 0
	movq	-24(%rbp), %rax
	cmpq	-32(%rbp), %rax
	jnb	.L4
	.loc 1 24 0
	movq	$1, -8(%rbp)
	jmp	.L5
.L6:
	.loc 1 26 0 discriminator 3
	movq	-40(%rbp), %rax
	subq	-8(%rbp), %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	subq	-8(%rbp), %rax
	movq	%rax, %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	.loc 1 24 0 discriminator 3
	addq	$1, -8(%rbp)
.L5:
	.loc 1 24 0 is_stmt 0 discriminator 1
	movq	-8(%rbp), %rax
	cmpq	-40(%rbp), %rax
	jbe	.L6
	jmp	.L7
.L4:
	.loc 1 31 0 is_stmt 1
	movq	$0, -8(%rbp)
	jmp	.L8
.L9:
	.loc 1 33 0 discriminator 3
	movq	-32(%rbp), %rdx
	movq	-8(%rbp), %rax
	addq	%rax, %rdx
	movq	-24(%rbp), %rcx
	movq	-8(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	.loc 1 31 0 discriminator 3
	addq	$1, -8(%rbp)
.L8:
	.loc 1 31 0 is_stmt 0 discriminator 1
	movq	-8(%rbp), %rax
	cmpq	-40(%rbp), %rax
	jb	.L9
.L7:
	.loc 1 36 0 is_stmt 1
	movq	-32(%rbp), %rax
.L3:
	.loc 1 37 0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	my_memmove, .-my_memmove
	.globl	my_memcpy
	.type	my_memcpy, @function
my_memcpy:
.LFB1:
	.loc 1 40 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	.loc 1 43 0
	movq	-24(%rbp), %rax
	cmpq	-32(%rbp), %rax
	jne	.L11
	.loc 1 44 0
	movq	-32(%rbp), %rax
	jmp	.L12
.L11:
	.loc 1 45 0
	movq	$0, -8(%rbp)
	jmp	.L13
.L14:
	.loc 1 47 0 discriminator 3
	movq	-32(%rbp), %rdx
	movq	-8(%rbp), %rax
	addq	%rax, %rdx
	movq	-24(%rbp), %rcx
	movq	-8(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	.loc 1 45 0 discriminator 3
	addq	$1, -8(%rbp)
.L13:
	.loc 1 45 0 is_stmt 0 discriminator 1
	movq	-8(%rbp), %rax
	cmpq	-40(%rbp), %rax
	jb	.L14
	.loc 1 49 0 is_stmt 1
	movq	-32(%rbp), %rax
.L12:
	.loc 1 50 0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	my_memcpy, .-my_memcpy
	.globl	my_memset
	.type	my_memset, @function
my_memset:
.LFB2:
	.loc 1 53 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, %eax
	movb	%al, -36(%rbp)
	.loc 1 55 0
	movq	$0, -8(%rbp)
	jmp	.L16
.L17:
	.loc 1 57 0 discriminator 3
	movq	-24(%rbp), %rdx
	movq	-8(%rbp), %rax
	addq	%rax, %rdx
	movzbl	-36(%rbp), %eax
	movb	%al, (%rdx)
	.loc 1 55 0 discriminator 3
	addq	$1, -8(%rbp)
.L16:
	.loc 1 55 0 is_stmt 0 discriminator 1
	movq	-8(%rbp), %rax
	cmpq	-32(%rbp), %rax
	jb	.L17
	.loc 1 59 0 is_stmt 1
	movq	-24(%rbp), %rax
	.loc 1 60 0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	my_memset, .-my_memset
	.globl	my_memzero
	.type	my_memzero, @function
my_memzero:
.LFB3:
	.loc 1 63 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	.loc 1 65 0
	movq	$0, -8(%rbp)
	jmp	.L20
.L21:
	.loc 1 67 0 discriminator 3
	movq	-24(%rbp), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	.loc 1 65 0 discriminator 3
	addq	$1, -8(%rbp)
.L20:
	.loc 1 65 0 is_stmt 0 discriminator 1
	movq	-8(%rbp), %rax
	cmpq	-32(%rbp), %rax
	jb	.L21
	.loc 1 69 0 is_stmt 1
	movq	-24(%rbp), %rax
	.loc 1 70 0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	my_memzero, .-my_memzero
	.globl	my_reverse
	.type	my_reverse, @function
my_reverse:
.LFB4:
	.loc 1 73 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	.loc 1 77 0
	movl	$1, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	.loc 1 79 0
	movq	$0, -16(%rbp)
	jmp	.L24
.L25:
	.loc 1 81 0 discriminator 3
	movq	-32(%rbp), %rax
	subq	-16(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %edx
	movq	-8(%rbp), %rax
	movb	%dl, (%rax)
	.loc 1 82 0 discriminator 3
	movq	-32(%rbp), %rax
	subq	-16(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movq	-24(%rbp), %rcx
	movq	-16(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	.loc 1 83 0 discriminator 3
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rax
	addq	%rax, %rdx
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	.loc 1 79 0 discriminator 3
	addq	$1, -16(%rbp)
.L24:
	.loc 1 79 0 is_stmt 0 discriminator 1
	movq	-32(%rbp), %rax
	shrq	%rax
	cmpq	-16(%rbp), %rax
	ja	.L25
	.loc 1 85 0 is_stmt 1
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free
	.loc 1 86 0
	movq	-24(%rbp), %rax
	.loc 1 87 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	my_reverse, .-my_reverse
	.globl	reserve_words
	.type	reserve_words, @function
reserve_words:
.LFB5:
	.loc 1 90 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	.loc 1 91 0
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	malloc
	.loc 1 92 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	reserve_words, .-reserve_words
	.globl	free_words
	.type	free_words, @function
free_words:
.LFB6:
	.loc 1 95 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	.loc 1 96 0
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free
	.loc 1 97 0
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	free_words, .-free_words
.Letext0:
	.file 2 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
	.file 3 "/usr/include/stdint.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x2a6
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF21
	.byte	0xc
	.long	.LASF22
	.long	.LASF23
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF9
	.byte	0x2
	.byte	0xd8
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
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF7
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF8
	.uleb128 0x2
	.long	.LASF10
	.byte	0x3
	.byte	0x26
	.long	0x62
	.uleb128 0x2
	.long	.LASF11
	.byte	0x3
	.byte	0x30
	.long	0x3f
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF12
	.uleb128 0x5
	.long	.LASF14
	.byte	0x1
	.byte	0x11
	.long	0xf3
	.quad	.LFB0
	.quad	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.long	0xf3
	.uleb128 0x6
	.string	"src"
	.byte	0x1
	.byte	0x11
	.long	0xf3
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x6
	.string	"dst"
	.byte	0x1
	.byte	0x11
	.long	0xf3
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x7
	.long	.LASF13
	.byte	0x1
	.byte	0x11
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0x8
	.string	"i"
	.byte	0x1
	.byte	0x13
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x9
	.byte	0x8
	.long	0x89
	.uleb128 0x5
	.long	.LASF15
	.byte	0x1
	.byte	0x27
	.long	0xf3
	.quad	.LFB1
	.quad	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.long	0x151
	.uleb128 0x6
	.string	"src"
	.byte	0x1
	.byte	0x27
	.long	0xf3
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x6
	.string	"dst"
	.byte	0x1
	.byte	0x27
	.long	0xf3
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x7
	.long	.LASF13
	.byte	0x1
	.byte	0x27
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0x8
	.string	"i"
	.byte	0x1
	.byte	0x29
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x5
	.long	.LASF16
	.byte	0x1
	.byte	0x34
	.long	0xf3
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x1a9
	.uleb128 0x6
	.string	"src"
	.byte	0x1
	.byte	0x34
	.long	0xf3
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x7
	.long	.LASF13
	.byte	0x1
	.byte	0x34
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x7
	.long	.LASF17
	.byte	0x1
	.byte	0x34
	.long	0x89
	.uleb128 0x2
	.byte	0x91
	.sleb128 -52
	.uleb128 0x8
	.string	"i"
	.byte	0x1
	.byte	0x36
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x5
	.long	.LASF18
	.byte	0x1
	.byte	0x3e
	.long	0xf3
	.quad	.LFB3
	.quad	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.long	0x1f3
	.uleb128 0x6
	.string	"src"
	.byte	0x1
	.byte	0x3e
	.long	0xf3
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x7
	.long	.LASF13
	.byte	0x1
	.byte	0x3e
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x8
	.string	"i"
	.byte	0x1
	.byte	0x40
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0xa
	.long	.LASF19
	.byte	0x1
	.byte	0x48
	.long	0xf3
	.quad	.LFB4
	.quad	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.long	0x24b
	.uleb128 0x6
	.string	"src"
	.byte	0x1
	.byte	0x48
	.long	0xf3
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x7
	.long	.LASF13
	.byte	0x1
	.byte	0x48
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x8
	.string	"i"
	.byte	0x1
	.byte	0x4a
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x8
	.string	"tmp"
	.byte	0x1
	.byte	0x4d
	.long	0xf3
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0xa
	.long	.LASF20
	.byte	0x1
	.byte	0x59
	.long	0x27b
	.quad	.LFB5
	.quad	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.long	0x27b
	.uleb128 0x7
	.long	.LASF13
	.byte	0x1
	.byte	0x59
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x9
	.byte	0x8
	.long	0x7e
	.uleb128 0xb
	.long	.LASF24
	.byte	0x1
	.byte	0x5e
	.quad	.LFB6
	.quad	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x6
	.string	"src"
	.byte	0x1
	.byte	0x5e
	.long	0x27b
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
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
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
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
	.uleb128 0x7
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
	.uleb128 0x8
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
	.uleb128 0x9
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
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
	.uleb128 0xb
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
.LASF12:
	.string	"long long int"
.LASF9:
	.string	"size_t"
.LASF15:
	.string	"my_memcpy"
.LASF19:
	.string	"my_reverse"
.LASF13:
	.string	"length"
.LASF0:
	.string	"long unsigned int"
.LASF11:
	.string	"uint8_t"
.LASF16:
	.string	"my_memset"
.LASF1:
	.string	"unsigned char"
.LASF8:
	.string	"char"
.LASF22:
	.string	"memory.c"
.LASF18:
	.string	"my_memzero"
.LASF10:
	.string	"int32_t"
.LASF20:
	.string	"reserve_words"
.LASF14:
	.string	"my_memmove"
.LASF2:
	.string	"short unsigned int"
.LASF4:
	.string	"signed char"
.LASF6:
	.string	"long int"
.LASF3:
	.string	"unsigned int"
.LASF23:
	.string	"/home/vipulgpt10/repos/pes_ecen5813/project_1/src"
.LASF17:
	.string	"value"
.LASF24:
	.string	"free_words"
.LASF5:
	.string	"short int"
.LASF21:
	.string	"GNU C99 5.4.0 20160609 -mtune=generic -march=x86-64 -g -O0 -std=c99 -fstack-protector-strong"
.LASF7:
	.string	"sizetype"
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
