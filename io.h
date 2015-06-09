#ifndef MIB_IO_H
#define MIB_IO_H

#ifndef __cplusplus
  #define __cplusplus 201402L
#endif

#include <iostream>
#include "macros.h"
#include "typedefs.h"

using namespace std;

#ifdef QSTRING_H
ostream& operator<< (ostream &out, const QString &first)
{
  return out << first.toStdString();
}

ostream& operator<< (ostream &out, const QByteArray &first)
{
  return out << first.data();
}
#endif // QSTRING_H

namespace mvc_utils
{
  namespace io
  {
    template <typename F>
    ostream& print(const F &first) { return cout<<first; }

    template <typename F, typename ...R>
    ostream& print(const F &first, const R& ...rest)
    {
      cout<<first;
      return print((rest)...);
    }

    template <typename F>
    void print_array(const F &_array, string seperator = "")
    {
      auto b =  std::begin(_array),e = std::end(_array);
      for ( ; b != e; ++b)
        cout<<*b <<"\t";
    }

    template <typename F>
    ostream& print_ln(const F &first) { return cout<<first <<endl; }

    template <typename F, typename ...R>
    ostream& print_ln(const F &first, const R& ...rest)
    {
      cout<<first <<endl;
      return print_ln(rest...);
    }

    template <typename T>
    ostream& print_w_tab(const T &val) { return cout<<val <<'\t'; }

    template <typename F, typename ...R>
    ostream& print_w_tab(const F &first, const R &...rest)
    {
      cout<<first <<"\t";
      return print_w_tab(rest...);
    }

    template <typename T>
    ostream& print_w_tab_ln(const T &val) { return cout <<val <<'\t' <<endl; }

    template <typename F, typename ...R>
    ostream& print_w_tab_ln(const F &first, const R& ...rest)
    {
      cout<<first <<'\t';
      print_w_tab((rest)...);
      return cout<<endl;
    }

    template <typename T>
    void print_map(const T &cont, string seperator = "")
    {
      auto iter = cont.begin();
      while (iter != cont.end())
      {
        print(iter->first, seperator, iter->second, seperator);
        ++iter;
      }
    }

    template <typename T>
    inline void print_pair(const T &cont, string seperator = "")
    {
      print(cont.first, seperator, cont.second, seperator);
    }

    template <typename T>
    void print_seq_cont(const T &cont, string seperator = "")
    {
      auto iter = cont.begin();
      while (iter != cont.end())
        if (iter == cont.end() - 1)
          print(*iter++);
        else
          print(*iter++, seperator);
    }

    template <typename Iter>
    void print_iter(Iter b, Iter e, const string &s = "")
    {
      while (b != e)
        cout<<*b++ <<s;
    }

    template <typename Iter>
    void print_iter_pair(Iter b, Iter e, const string &s = "")
    {
      while (b != e)
      {
        cout  <<(*b++).first <<s
              <<(*b).second  <<s <<endl;
      }
    }
  }
}

#endif //MIB_IO_H
