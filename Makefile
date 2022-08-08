build_dir="build"
working_dir=$(shell pwd)

color_red    := $(shell tput -Txterm setaf 1)
color_green  := $(shell tput -Txterm setaf 2)
color_yellow := $(shell tput -Txterm setaf 3)
color_clear 	 := $(shell tput -Txterm sgr0)

all: clean config
	@(cd ${build_dir} && make)

config: clean
	@(echo "\n${color_yellow}Running config${color_clear}")
	@mkdir ${build_dir}
	@(cd ${build_dir} && cmake ..)

clean:
	@(echo "\n${color_yellow}Running clean${color_clear}")
	@(echo "${color_green}Cleaning ${working_dir}/${build_dir}${color_clear}")
	@rm -rf ${build_dir}
	@echo "${color_green}Done${color_clear}"