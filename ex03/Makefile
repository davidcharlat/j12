SRCFILES = ft_hexdump \
			print \
			ft_strcmp \

TARGET = ft_hexdump

all:
	gcc -o $(TARGET) $(addsuffix .c, $(SRCFILES)) 

clean:
	rm -f $(addsuffix .o, $(SRCFILES))
	
fclean: clean
	rm -f $(TARGET)
	
re: fclean all
