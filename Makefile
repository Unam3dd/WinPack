CC = cl.exe
NAME = wpack
LINK = link.exe
CFLAGS = /c /I includes /EHsc
FLAGS_C_CXX = /TP
LFLAGS = /MACHINE:x86 /LIBPATH:lib LIEF.lib /OUT:

CXX_FILES = src/main.cxx \
			src/packer/packer.cxx \
			src/cipher/cipher.c

OBJS_PACK = main.obj packer.obj cipher.obj

all:
	$(CC) $(CFLAGS) $(FLAGS_C_CXX) $(CXX_FILES)
	$(LINK) $(OBJS_PACK) $(LFLAGS)$(NAME).exe

clean:
	del $(OBJS_PACK) /S /Q

fclean:
	del $(OBJS_PACK) /S /Q
	del $(NAME).exe /S /Q