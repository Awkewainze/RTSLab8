SHELL = /bin/sh
SRCDIR = .
CC = gcc
#CC = gcc
YACC = bison -y
CDEBUG = -g
COMPLIANCE_FLAGS = -save-temps

CFLAGS = $(COMPLIANCE_FLAGS) $(CDEBUG) -I. -I$(SRCDIR)
LDFLAGS = -g
LIBS = -lm -lpthread -lrt

############################################################################################################
# List your sources here.
SOURCES = client.c server.c 
############################################################################################################

############################################################################################################
# list the name of your output program here.
SERVER = server
CLIENT = client

############################################################################################################
# Create the names of the object files (each .c file becomes a .o file)
OBJS = $(patsubst %.c, %.o, $(SOURCES))

include $(SOURCES:.c=.d)

all : $(OBJS) $(SERVER) $(CLIENT)


$(SERVER) : $(OBJS)
	$(CC) -o $(SERVER)  server.o $(LIBS)

$(CLIENT) : $(OBJS)
	$(CC) -o $(CLIENT)  client.o $(LIBS)

	
%.o : %.c #Defines how to translate a single c file into an object file.
	echo compiling $<
	$(CC) $(CFLAGS) -c $<

%.d : %.c #Defines how to generate the dependencies for the given files.  -M gcc option generates dependencies.
	@set -e; rm -f $@; \
	$(CC) $(COMPLIANCE_FLAGS ) -M $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	 rm -f $@.$$$$

clean :   # Delete any and all artifacts from the build.  The only thing which is kept is the source code.
	rm -f *.o
	rm -f *.i
	rm -f *.s
	rm -f *.d
	rm -f $(SERVER)
	rm -r $(CLIENT)
