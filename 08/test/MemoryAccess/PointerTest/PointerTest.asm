@256
D=A
@SP
M=D
//// This file is part of www.nand2tetris.org

//// and the book "The Elements of Computing Systems"

//// by Nisan and Schocken, MIT Press.

//// File name: projects/07/MemoryAccess/PointerTest/PointerTest.vm

//

//// Executes pop and push commands using the 

//// pointer, this, and that segments.

@3030
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 3030

@SP
M=M-1
A=M
D=M
@THIS
M=D
//pop pointer 0

@3040
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 3040

@SP
M=M-1
A=M
D=M
@THAT
M=D
//pop pointer 1

@32
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 32

@THIS
D=M
@2
D=D+A
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
//pop this 2

@46
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 46

@THAT
D=M
@6
D=D+A
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
//pop that 6

@THIS
D=M
@SP
M=M+1
A=M-1
M=D
//push pointer 0

@THAT
D=M
@SP
M=M+1
A=M-1
M=D
//push pointer 1

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=M+D
M=D
//add

@2
D=A
@THIS
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
//push this 2

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=M-D
M=D
//sub

@6
D=A
@THAT
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
//push that 6

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=M+D
M=D
//add

