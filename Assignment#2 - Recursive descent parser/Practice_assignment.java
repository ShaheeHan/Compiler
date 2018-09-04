
package practice_assignment;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Vector;

/**
 *
 * @author Jahid Raihan
 * Roll : 10
 */

class Check
{
    String Input;
    int index;
    int level; 
    Vector<String> vec;
    Check(String in)
    {
        Input= in+"$";
        index=0;
        level=0;
        vec= new Vector<String>();
    }
    public boolean goal(int x)
    {
        boolean flag;
        
        vec.add(insert_tab(x)+"goal");
        flag = expr(x+1);
        return flag;
    }
    
    boolean expr(int x)
    {
        vec.add(insert_tab(x)+"expr");
        if(term(x+1)&&expr2(x+1))
            return true;
        else
            return false;
    }
    
    boolean expr2(int x)
    {
        vec.add(insert_tab(x)+"expr2");
        if(Input.charAt(index)=='+')
        {
            index++;
            if(term(x+1)&&expr2(x+1))
                return true;
            else
                return false;
        }
        
        else if(Input.charAt(index)=='-')
        {
            index++;
            if(term(x+1)&& expr2(x+1))
                return true;
            else
                return false;
        }
        else 
            return true;
        
    }

    boolean term(int x)
    {
        vec.add(insert_tab(x)+"term");
        if(factor(x+1)&&term2(x+1))
            return true;
        else 
            return false;
    }
    boolean term2(int x)
    {
        vec.add(insert_tab(x)+"term2");
        if(Input.charAt(index)=='*'||Input.charAt(index)=='/')
        {
            index++;
            if(factor(x+1)&& term2(x+1))
                return true;
            else
                return false;
        }
        else
            return true;
    }
    boolean factor(int x)
    {
        vec.add(insert_tab(x)+"factor");
        if(Input.charAt(index)>=48&&Input.charAt(index)<=57)
        {
          index++;
          return true;  
        }
        else if((Input.charAt(index)>=65&&Input.charAt(index)<=90)||(Input.charAt(index)>=97&&Input.charAt(index)<=122))
        {
            index++;
            return true;
        }
        else if(Input.charAt(index)=='(')
        {
            index++;
            if(expr(x+1)&&Input.charAt(index)==')')
            {
                index++;
                return true;
            }
            else return false;
              
        }
        else 
            return false;      
    }
    String insert_tab(int x)
    {
        String s=" ";
        if(x==0)
        {
            return s;
        }
        else
        {
            for(int i=1;i<=x;i++)
            {
                s+='\t';
                //System.out.println(s+" -- test");
            }
            return s;
        }
    }
    
}


public class Practice_assignment {
    static String RemoveSpace (String s)
    {
        String st="";
        
        for(int j=0;j<s.length();j++)
        {
            if(s.charAt(j)==' ')
            {
                continue;
            }
            st+=s.charAt(j);
        }
        return st;
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
       
       
        
        File file = new File("input.txt");
        Scanner sc = new Scanner(file);
        try (Writer writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("output.txt"), "utf-8")))
        {
                 //writer.write("something");
                 while(sc.hasNextLine())
                 {
                    String input;
                    input = sc.nextLine();
                    writer.write("Input : "+input+"\n");
                    input=RemoveSpace(input);

                    Check object=new Check(input);
                    if(object.goal(0)&&(object.index==input.length()))
                    {
                        writer.write("String Accepted\n");
                        for(int i=0;i<object.vec.size();i++)
                        {
                            writer.write(object.vec.get(i));
                            writer.write("\n");
                        }
                    }
                    else 
                       writer.write("String Rejected\n");
                 }
        }
        
    }
}
