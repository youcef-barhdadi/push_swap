


function  generateNumbers()
{
    number=""
    # echo "number is $1 ll"
    for n in {1..5}
    do
        number+=`echo $RANDOM`
        number+=" "
    done
    echo  "$number"
}


 numbers=$(generateNumbers $n)


for n in {1..100}
do
    # numbers=""
    numbers=$(generateNumbers $n)
    
    echo $numbers
   lines=`./a.out $numbers | wc -l`
   ./a.out $numbers | ./checker_linux $numbers
   echo "number of lines $lines"
done