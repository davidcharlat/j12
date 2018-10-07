SRCFILES = ft_hexdump \
			print

TARGET = ft_hexdump

all:
	gcc -o $(TARGET) $(addsuffix .c, $(SRCFILES)) libft.a
		
clean:
	rm -f $(addsuffix .o, $(SRCFILES))
	
fclean: clean
	rm -f $(TARGET)
	
re: fclean all
