#!/bin/bash

# Check for Ruby
which ruby
if [ $? -ne 0 ]
then
   echo "Can't find ruby. You need to install Ruby."
   exit 1
fi

# Check for gem
which gem
if [ $? -ne 0 ]
then
   echo "Can't find gem program. You need to install RubyGems."
fi

# Install needed Gems
gem install parse_fasta
gem install abort_if

# Compile the C lib.
ruby extconf.rb && make && mkdir -p lib && mv pss.bundle lib
