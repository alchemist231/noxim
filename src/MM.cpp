#include "MM.h"
#include "myParam.h"
using namespace std;

mm::gp_t* mm::allocate()
{
  if(globalTraceMm==true) { cout<<"mm::allocate called"<<endl;}

  gp_t* ptr;
  if (free_list)
  {
    ptr = free_list->trans;
    empties = free_list;
    free_list = free_list->next;
  }
  else
  {
    ptr = new gp_t(this);
  }
  return ptr;
}

void mm::free(gp_t* trans)
{

  if(globalTraceMm==true) { cout<<"mm::free called"<<endl;}

  if (!empties)
  {
    empties = new access;
    empties->next = free_list;
    empties->prev = 0;
    if (free_list)
      free_list->prev = empties;
  }
  free_list = empties;
  free_list->trans = trans;
  empties = free_list->prev;
}
