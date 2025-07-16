import sumatra;
import System.out.println;

int main() {
  String s = "hello world";
  String s2 = "hello world";
  char data[] = {'a', 'b', 'c'};
  String t = new String(data);
  String u = new String();
  String v;
  Object o;
  Object o2 = new String("abc");
  // "hello world"
  System.out.println(s);
  // "abc"
  System.out.println(t);
  // ""
  System.out.println(u);
  // null
  System.out.println(o);
  // PKW6Object6Object#<some hex digits>
  System.out.println(o2);
  // true
  System.out.println(v == null);
  // true
  System.out.println(s.equals(s2));
  // false
  System.out.println(s == s2);
  // false
  System.out.println(s.equals(t));
}
