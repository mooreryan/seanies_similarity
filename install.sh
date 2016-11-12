#!/bin/bash
ruby extconf.rb && make && mkdir -p lib && mv pss.bundle lib
