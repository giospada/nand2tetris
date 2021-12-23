@256
D=A
@SP
M=D
//// This file is part of www.nand2tetris.org

//// and the book "The Elements of Computing Systems"

//// by Nisan and Schocken, MIT Press.

//// File name: projects/07/MemoryAccess/BasicTest/BasicTest.vm

//

//// Executes pop and push commands using the virtual memory segments.

@10
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 10

@LCL
D=M
@0
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
//pop local 0

@21
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 21

@22
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 22

@ARG
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
//pop argument 2

@ARG
D=M
@1
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
//pop argument 1

@36
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 36

@THIS
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
//pop this 6

@42
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 42

@45
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 45

@THAT
D=M
@5
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
//pop that 5

@THAT
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
//pop that 2

@510
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 510

@5
D=A
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
//pop temp 6

@0
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
//push local 0

@5
D=A
@THAT
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
//push that 5

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=M+D
M=D
//add

@1
D=A
@ARG
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
//push argument 1

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
@THIS
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
//push this 6

@6
D=A
@THIS
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
//push this 6

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=M+D
M=D
//add

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
@5
A=D+A
D=M
@SP
M=M+1
A=M-1
M=D
//push temp 6

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=M+D
M=D
//add

