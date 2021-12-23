@256
D=A
@SP
M=D
//// This file is part of www.nand2tetris.org

//// and the book "The Elements of Computing Systems"

//// by Nisan and Schocken, MIT Press.

//// File name: projects/07/MemoryAccess/StaticTest/StaticTest.vm

//

//// Executes pop and push commands using the static segment.

@111
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 111

@333
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 333

@888
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 888

@SP
M=M-1
A=M
D=M
@StaticTest.8
M=D
//pop static 8

@SP
M=M-1
A=M
D=M
@StaticTest.3
M=D
//pop static 3

@SP
M=M-1
A=M
D=M
@StaticTest.1
M=D
//pop static 1

@StaticTest.3
D=M
@SP
M=M+1
A=M-1
M=D
//push static 3

@StaticTest.1
D=M
@SP
M=M+1
A=M-1
M=D
//push static 1

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=M-D
M=D
//sub

@StaticTest.8
D=M
@SP
M=M+1
A=M-1
M=D
//push static 8

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=M+D
M=D
//add

