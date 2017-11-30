#include <check.h>
#include "../src/osc.h"

START_TEST (check_osc_compute)
{
  Osc par = {0,1,0};
  Sample out;
  Sample *osc_compute(Sample*,Osc*);

  osc_compute(&out,&par);
  ck_assert_double_eq(out.value,1.0);
  ck_assert_double_eq(out.time,0.0);


}
END_TEST

int main(void)
{
    return 0;
}
