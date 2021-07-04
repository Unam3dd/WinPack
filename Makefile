CC = cl.exe
NAME = wpack
LINK = link.exe
CFLAGS = /c /TC /I includes
LFLAGS = /MACHINE:x86 /OUT:$(NAME)

SRCS = src/main.c \
	   src/utils/utils.c \
	   src/loader/loader.c 

OBJS = main.obj utils.obj loader.obj

all:
	$(CC) $(CFLAGS) $(SRCS)
	$(LINK) $(OBJS) $(LFLAGS).exe

clean:
	del $(OBJS) /S /Q

fclean:
	del $(OBJS) /S /Q
	del $(NAME).exe /S /Q
