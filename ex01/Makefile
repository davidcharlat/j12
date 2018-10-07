SRCFILES = ft_cat 
TARGET = ft_cat 

all:
	gcc -o $(TARGET) $(addsuffix .c, $(SRCFILES))
		
clean:
	rm -f $(addsuffix .o, $(SRCFILES))
	
fclean: clean
	rm -f $(TARGET)
	
re: fclean all
