#include <ruby.h>

/* modules */
VALUE mPss;

/*
# @note Requires that seq only has "-" for gaps, so it must be tr-ed
#   before being passed
def non_gap_posns seq
  (0 ... seq.length).reject do |idx|
    seq[idx] == "-"
  end
end
*/
/* len will always be 0 < len < 50,000 */
static VALUE non_gap_posns(VALUE obj, VALUE seq)
{
  long i = 0;
  long len = RSTRING_LEN(seq);

  VALUE ary = rb_ary_new2(len);

  char * str = StringValueCStr(seq);

  for (i = 0; i < len; ++i) {
    if (str[i] != '-') {
      rb_ary_push(ary, LONG2NUM(i));
    }
  }

  return ary;
}

static VALUE shared_non_gap_posns(VALUE obj, VALUE seq1, VALUE seq2)
{
  long i = 0;
  long len = RSTRING_LEN(seq1);

  //  VALUE ary = rb_ary_new2(len);
  VALUE ary[len];
  long ary_i = 0;

  char * s1 = StringValueCStr(seq1);
  char * s2 = StringValueCStr(seq2);

  for (i = 0; i < len; ++i) {
    if (s1[i] != '-' || s2[i] != '-') {
      //rb_ary_push(ary, LONG2NUM(i));
      ary[ary_i++] = LONG2NUM(i);
    }
  }

  return rb_ary_new_from_values(ary_i, ary);
}


/*
(0 ... s1_length).each do |idx|
  matches += 1 if s1[idx] == s2[idx]
end
*/
static VALUE num_matches(VALUE obj, VALUE str1, VALUE str2, VALUE length)
{
  long i = 0;
  long len = NUM2LONG(length);
  long matches = 0;

  char * s1 = StringValueCStr(str1);
  char * s2 = StringValueCStr(str2);

  for(i = 0; i < len; ++i) {
    if (s1[i] == s2[i]) {
      ++matches;
    }
  }

  return LONG2NUM(matches);
}

/*
def degap_seq non_gap_posns, seq
  non_gap_posns.map { |i| seq[i] }.join
end
*/
static VALUE degap_seq(VALUE obj, VALUE non_gap_posns, VALUE seq)
{
  long i = 0;
  long str_i = 0;

  char * str = StringValueCStr(seq);

  long len = RARRAY_LEN(non_gap_posns);

  VALUE * ng_posns = RARRAY_PTR(non_gap_posns);

  char dg_str[len+1];

  for (i = 0; i < len; ++i) {
    str_i = NUM2LONG(ng_posns[i]);
    dg_str[i] = str[str_i];
  }

  dg_str[i] = '\0';

  return rb_str_new_cstr(dg_str);
}

void Init_pss(void)
{
  mPss = rb_define_module("Pss");

  rb_define_module_function(mPss, "non_gap_posns", non_gap_posns, 1);
  rb_define_module_function(mPss, "num_matches", num_matches, 3);
  rb_define_module_function(mPss, "degap_seq", degap_seq, 2);
  rb_define_module_function(mPss, "shared_non_gap_posns", shared_non_gap_posns, 2);
}
