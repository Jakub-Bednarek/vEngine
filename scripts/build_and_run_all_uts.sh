#! /bin/bash
color_red=$(tput -Txterm setaf 1)
color_green=$(tput -Txterm setaf 2)
color_clear=$(tput -Txterm sgr0)

ut_dirs=$(find $1 -name "tests")
if [ -z $ut_dirs ]; then
    echo No tests to run!
    exit 0
fi

echo ${color_green}Discovered ${#ut_dirs[@]} UTs${color_clear}

failed_uts=()

for ut in $ut_dirs; do
    cd $ut && make
    executable=$(find . -name "*_test")
    if ! ./$executable; then
        failed_uts+=($(basename -- $executable))
    fi
done

echo 
echo -------- Summary --------
if [ ! ${#failed_uts[@]} -eq 0 ]; then
    for failed in $failed_uts; do
        echo \* $failed${color_red} - FAILED${color_clear}
    done
else
    echo ${color_green}All tests passed!${color_clear}
fi