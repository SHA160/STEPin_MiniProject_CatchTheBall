PROJ_NAME = CathTheBall
TEST_PROJ_NAME = Test_$(PROJ_NAME)

BUILD_DIR = Build

SRC =  main.c\
src/DisplayBorder.c

TEST_SRC = test/test.c\
unity/unity.c

#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

TEST_OUTPUT = $(BUILD_DIR)/Test_$(PROJ_NAME).$(EXEC)

INC = -Iinc\
-Iunity

INCLUDE_LIBS = -lcunit

# Project Output name
PROJECT_OUTPUT = $(BUILD_DIR)/$(PROJ_NAME).$(EXEC)

# Document files
DOCUMENTATION_OUTPUT = documentation/html




# Makefile will not run target command if the name with file already exists. To override it ,we use .PHONY
.PHONY : all test coverage run clean documentation

#all:  $(BUILD_DIR) 
#	gcc $(SRC) $(INC) -o $(PROJECT_OUTPUT)
all:$(SRC) $(BUILD_DIR) 
	gcc  $(SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

test:$(BUILD_DIR)
	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) $(INCLUDE_LIBS)
	./$(TEST_OUTPUT)
#test: $(SRC) $(TEST_SRC) $(BUILD_DIR)
#	gcc $^ $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
#	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))

coverage:$(TEST_SRC)
	gcc -fprofile-arcs -ftest-coverage $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) $(INCLUDE_LIBS)
	./$(TEST_OUTPUT)
	gcov -a DisplayBorder.c

#coverage:${PROJECT_NAME}
#	gcc -fprofile-arcs -ftest-coverage  $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
#	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
#	gcov -a $(SRC)

doc:
	make -C ./documentation
analyze: test memcheck staticcheck coverage sanitize_check

staticcheck:$(BUILD_DIR)
	cppcheck --enable=all -iunity .

memcheck: $(BUILD_DIR)
	valgrind ./$(TEST_OUTPUT)

sanitize_check: $(BUILD_DIR)
	gcc -fsanitize=address -fno-omit-frame-pointer $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) $(INCLUDE_LIBS)
	./$(TEST_OUTPUT)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(DOCUMENTATION_OUTPUT) *.gcda *.gcno *.gcov
