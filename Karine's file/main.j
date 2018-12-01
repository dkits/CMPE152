.class public main
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;

.method public static main([Ljava/lang/String;)V

	new RunTimer
	dup
	invokenonvirtual RunTimer/<init>()V
	putstatic        0x7fcc9e614ab0/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V

; 193;

	ldc	193;

; inta,b,c;

	ldc	inta,b,c;
	ldc	a=6;

; boole=false;

	ldc	boole=false;

; if(a==5){d=12;}elseif(a==4){d=1;d=3;}else{d=2;}

	ldc	if(a==5){d=12;}elseif(a==4){d=1;d=3;}else{d=2;}
	ldc	{d=12;}

; if(a==4){d=1;d=3;}else{d=2;}

	ldc	if(a==4){d=1;d=3;}else{d=2;}
	ldc	{d=1;d=3;}
	ldc	d=3;
	ldc	{d=2;}
	ldc	while(x>1){x=x-1;x=x-2;x=x-3;}

; while(x>1){x=x-1;x=x-2;x=x-3;}

	ldc	{x=x-1;x=x-2;x=x-3;}
	ldc	x=x-2;
	ldc	x=x-3;

; proc_two_eq(12,2,56);

	ldc	proc_two_eq(12,2,56);

; voidproc_two_eq(help,we,yt,LOL,WAT){x=2;}

	ldc	voidproc_two_eq(help,we,yt,LOL,WAT){x=2;}
	ldc	{x=2;}

; intproc_two_eq(#help,#we,#yt){K=as;x=2;e=2;returnK;}

	ldc	intproc_two_eq(#help,#we,#yt){K=as;x=2;e=2;returnK;}
	ldc	{K=as;x=2;e=2;returnK;}
	ldc	x=2;
	ldc	e=2;

; voidsomething{boolpo=true;intx;x=2;}

	ldc	voidsomething{boolpo=true;intx;x=2;}
	ldc	{boolpo=true;intx;x=2;}

; boolpo=true;

	ldc	boolpo=true;

; intx;

	ldc	intx;
	ldc	x=2;

	getstatic     0x7fcc9e614ab0/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
