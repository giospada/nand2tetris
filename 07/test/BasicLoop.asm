@256
D=A
@SP
M=D
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
todo
(LOOP_START)
@0
D=A
todo
A=D+M
D=A
@SP
A=M
M=D
@SP
M=M+1
@0
D=A
todo
A=D+M
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=M+D
M=D
@SP
M=M-1
A=M
D=M
todo
@0
D=A
todo
A=D+M
D=A
@SP
A=M
M=D
@SP
M=M+1
@1
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@SP
A=M-1
D=M-D
M=D
@SP
M=M-1
A=M
D=M
todo
@0
D=A
todo
A=D+M
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@LOOP_START
D;JNE
@0
D=A
todo
A=D+M
D=A
@SP
A=M
M=D
@SP
M=M+1
