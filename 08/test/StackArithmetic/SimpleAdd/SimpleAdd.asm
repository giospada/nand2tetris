@256
D=A
@SP
M=D
//// This file is part of www.nand2tetris.org

//// and the book "The Elements of Computing Systems"

//// by Nisan and Schocken, MIT Press.

//// File name: projects/07/StackArithmetic/SimpleAdd/SimpleAdd.vm

//

//// Pushes and adds two constants.

@7
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 7

@8
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 8

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=M+D
M=D
//add

