#CC =gcc
all : union select tri fusion commande

union : union.c    
    $(CC) -Wall -o union union.c
select : select.c
    $(CC) -Wall -o select select.c
tri : tri.c
    $(CC) -Wall -o tri tri.c
fusion : fusion.c
    $(CC) -Wall -o fusion fusion.c
moyenne : moyenne.c
    $(CC) -Wall -o moyennne moyenne.c
clean :
    rm union
	rm select
	rm tri
	rm commande
	rm fusion
