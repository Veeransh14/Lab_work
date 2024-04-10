import java.net.*;
import java.awt.*;
import java.awt.event.*;
import java.applet.*;

/*<applet code="Cpdemo" width=500 height=600>
  </applet>
*/
public class Cpdemo extends Applet implements ActionListener
{
  Panel p1,p2,p3;
  Checkbox c1,c2;
  CheckboxGroup cbg;
  TextArea ta;
  Button b1,b2,b3;

 public void init()
  {
    setLayout(new BorderLayout());

    p1=new Panel(new FlowLayout());
    p2=new Panel(new GridLayout(2,2));
    p3=new Panel(new FlowLayout(FlowLayout.CENTER));

    cbg=new CheckboxGroup();

    c1=new Checkbox("FOREGROUND",cbg,true);
    c2=new Checkbox("BACKGROUND",cbg,false);

    p1.add(c1);
    p1.add(c2);

    add(p1,BorderLayout.NORTH);

    b1=new Button("RED");
    b2=new Button("BLUE");
    b3=new Button("GREEN");
    b1.setBackground(Color.RED);
    b2.setBackground(Color.BLUE);
    b3.setBackground(Color.GREEN);

    p2.add(b1);
    p2.add(b2);
    p2.add(b3);

    add(p2,BorderLayout.CENTER);

    ta=new TextArea("My first Applet project\nName:Pratham Shah\nID:221070061",5,20);

    p2.add(ta);

    add(p3,BorderLayout.SOUTH);

    //c1.addItemListener(this);
    //c2.addItemListener(this);

    b1.addActionListener(this);
    b2.addActionListener(this);
    b3.addActionListener(this);
}
   public void actionPerformed(ActionEvent ae)
    {
      String str=ae.getActionCommand();
      String str1=cbg.getSelectedCheckbox().getLabel();
      System.out.println(str1);

      if(str1.equals("FOREGROUND"))
        {

          if(str=="RED")
           ta.setForeground(Color.red);

          if(str=="BLUE")
           ta.setForeground(Color.blue);

          if(str=="GREEN")
           ta.setForeground(Color.green);
	   }

      else
      {
          if(str=="RED")
           ta.setBackground(Color.red);

          if(str=="BLUE")
           ta.setBackground(Color.blue);

          if(str=="GREEN")
           ta.setBackground(Color.green);
        }
    }
}