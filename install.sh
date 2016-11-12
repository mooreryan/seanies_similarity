#!/bin/bash

which gem
if [ $? -ne 0 ]
then
   echo "Can't find gem program. You need to install RubyGems."
fi

gem install parse_fasta
gem install abort_if

which ruby
if [ $? -ne 0 ]
then
   echo "Can't find ruby. You need to install Ruby."
   exit 1
fi

ruby extconf.rb && make && mkdir -p lib && mv pss.bundle lib
