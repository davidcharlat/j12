SRCFILES = ft_tail \
		   print_file \
		   print_err \
		   ft_strcmp \
		   ft_atoi
TARGET = ft_tail

all:
	gcc -o $(TARGET) $(addsuffix .c, $(SRCFILES))

clean:
	rm -f $(addsuffix .o, $(SRCFILES))
	
fclean: clean
	rm -f $(TARGET)
	
re: fclean all
