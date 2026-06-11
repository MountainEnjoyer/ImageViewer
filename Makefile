FLAGS = *.c

comp :
	gcc -o a.out ${FLAGS}

exec :
	gcc -o a.out ${FLAGS} 
	./a.out
	exit
