# Seanie's Similarity

Seanie wants what Seanie wants. And today, Seanie wants his special pairwise sequence similarity metric....

## Install it!

You need to have Ruby, RubyGems, and a C compiler installed.

```bash
$ git clone https://github.com/mooreryan/seanies_similarity.git
$ cd seanies_similarity
$ ./install.sh
/Users/moorer/.rvm/rubies/ruby-2.3.0/bin/gem
Successfully installed parse_fasta-2.2.0
Parsing documentation for parse_fasta-2.2.0
Done installing documentation for parse_fasta after 0 seconds
1 gem installed
Successfully installed abort_if-0.1.2
Parsing documentation for abort_if-0.1.2
Done installing documentation for abort_if after 0 seconds
1 gem installed
/Users/moorer/.rvm/rubies/ruby-2.3.0/bin/ruby
creating Makefile
compiling pss.c
linking shared-object lib/pss.bundle
```

Currently, the  `pairwise_sequence_similarity` must remain in this directory to work. But you can make a symlink to a location on your path if you want.

```bash
$ ln -s `pwd`/pairwise_sequence_similarity ~/bin/pairwise_sequence_similarity
```

Since, `~/bin` is on my path, I can use this spiffy program from wherever!

## Run tests!

```bash
$ ./test.sh
Test 1: Success!
Test 2: Success!
```

## Use it!

```bash
USAGE: ./pairwise_sequence_similarity aligned_seqs.fa <aln_length (default: 50,000)>
```

### Example

A test file...

```bash
$ cat test_files/test.fa
>s1
.....T-GG-A..
>s2
-----t-gg--t-
>s3
--AAAU-U---U-
>s4
---AA--------
```

Run the program...

```bash
$ ./pairwise_sequence_similarity test_files/test.fa 13
I, [2016-11-11T23:19:12.498380 #73994]  INFO -- : Processing 6 combinations for 4 sequences
I, [2016-11-11T23:19:12.498890 #73994]  INFO -- : Done!
```

And the resulting file...

```bash
$ cat test_files/test.fa.similarity.txt
seq1	seq2	matches	total_compared	percent
s1	s2	3	4.0	75.0
s1	s3	1	4.0	25.0
s1	s4	0	0.0	NaN
s2	s3	2	4.0	50.0
s2	s4	0	0.0	NaN
s3	s4	2	2.0	100.0
```

- `U` and `T` are treated as being equal. 
- Case insensitive
- Some of these are `NaN` because some sequences don't overlap each other at any base.

## Uninstall it!

You hate the program? No problem!

```bash
$ ./uninstall.sh
```

Just you try and use it now! ^__^