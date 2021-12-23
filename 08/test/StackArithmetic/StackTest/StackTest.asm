@256
D=A
@SP
M=D
//// This file is part of www.nand2tetris.org

//// and the book "The Elements of Computing Systems"

//// by Nisan and Schocken, MIT Press.

//// File name: projects/07/StackArithmetic/StackTest/StackTest.vm

//

//// Executes a sequence of arithmetic and logical operations

//// on the stack. 

@17
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 17

@17
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 17

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=D-M
M=0
@ENDCOND1
D;JNE
@SP
A=M-1
M=!M
(ENDCOND1)
//eq

@17
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 17

@16
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 16

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=D-M
M=0
@ENDCOND2
D;JNE
@SP
A=M-1
M=!M
(ENDCOND2)
//eq

@16
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 16

@17
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 17

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=D-M
M=0
@ENDCOND3
D;JNE
@SP
A=M-1
M=!M
(ENDCOND3)
//eq

@892
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 892

@891
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 891

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=D-M
M=0
@ENDCOND4
D;JLE
@SP
A=M-1
M=!M
(ENDCOND4)
//lt

@891
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 891

@892
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 892

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=D-M
M=0
@ENDCOND5
D;JLE
@SP
A=M-1
M=!M
(ENDCOND5)
//lt

@891
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 891

@891
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 891

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=D-M
M=0
@ENDCOND6
D;JLE
@SP
A=M-1
M=!M
(ENDCOND6)
//lt

@32767
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 32767

@32766
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 32766

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=D-M
M=0
@ENDCOND7
D;JGE
@SP
A=M-1
M=!M
(ENDCOND7)
//gt

@32766
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 32766

@32767
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 32767

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=D-M
M=0
@ENDCOND8
D;JGE
@SP
A=M-1
M=!M
(ENDCOND8)
//gt

@32766
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 32766

@32766
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 32766

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=D-M
M=0
@ENDCOND9
D;JGE
@SP
A=M-1
M=!M
(ENDCOND9)
//gt

@57
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 57

@31
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 31

@53
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 53

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=M+D
M=D
//add

@112
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 112

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=M-D
M=D
//sub

@SP
A=M-1
M=-M
//neg

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=M&D
M=D
//and

@82
D=A
@SP
M=M+1
A=M-1
M=D
//push constant 82

@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=M|D
M=D
//or

@SP
A=M-1
M=!M
//not

