dir_to_backup=$1
mkdir $3 2> /dev/null
ext=$2
backup_dir=$(pwd)/$3
cd $dir_to_backup 2> /dev/null
dfs () {
  names=$(ls)
  for name in $names
  do
    if [ -d ./$name ] 
    then 
      cd $name 2> /dev/null
      dfs
      cd .. 2> /dev/null
    else
      if [ ${name##*.} == $ext ] && [ -f ./$name ]
      then
        new_file_name=$name
        k=1  
        while [ -f $backup_dir/$new_file_name ]
        do  
          new_file_name=$k$name
          ((k++))
        done
        cp $name $backup_dir/$new_file_name 2> /dev/null
      fi
    fi
  done
}
dfs
cd $backup_dir 2> /dev/null
cd .. 2> /dev/null
tar -cvf $4 $3 2> /dev/null
echo "done"