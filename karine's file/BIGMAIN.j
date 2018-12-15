.class public BIGMAIN
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;

; e->bool;

.field private static e B

; d->float;

.field private static d F

; a,x->int;

.field private static a I
.field private static x I



.method public static main([Ljava/lang/String;)V
 
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "hi"
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V


	new RunTimer
	dup
	invokenonvirtual RunTimer/<init>()V
	putstatic        BIGMAIN/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V
	putstatic        BIGMAIN/_standardIn LPascalTextIn;

; a=6;

	ldc	6
	putstatic	BIGMAIN/a I

; d=1.1;

	ldc	1.1
	putstatic	BIGMAIN/d F

; print("hi");


	getstatic     BIGMAIN/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
