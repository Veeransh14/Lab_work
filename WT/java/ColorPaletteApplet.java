import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ColorPaletteApplet extends JFrame implements ActionListener {
    JButton redButton, greenButton, blueButton, customButton;
    JPanel colorPanel;
    Color color = Color.black;

    public ColorPaletteApplet() {
        setTitle("Color Palette");
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        redButton = new JButton("Red");
        greenButton = new JButton("Green");
        blueButton = new JButton("Blue");
        customButton = new JButton("Custom");

        colorPanel = new JPanel();
        colorPanel.setPreferredSize(new Dimension(100, 100));
        colorPanel.setBackground(color);

        redButton.addActionListener(this);
        greenButton.addActionListener(this);
        blueButton.addActionListener(this);
        customButton.addActionListener(this);

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(redButton);
        buttonPanel.add(greenButton);
        buttonPanel.add(blueButton);
        buttonPanel.add(customButton);

        setLayout(new BorderLayout());
        add(buttonPanel, BorderLayout.NORTH);
        add(colorPanel, BorderLayout.CENTER);
    }

    public void actionPerformed(ActionEvent ae) {
        if (ae.getSource() == redButton) {
            color = Color.red;
        } else if (ae.getSource() == greenButton) {
            color = Color.green;
        } else if (ae.getSource() == blueButton) {
            color = Color.blue;
        } else if (ae.getSource() == customButton) {
            color = JColorChooser.showDialog(this, "Choose a color", color);
        }

        colorPanel.setBackground(color);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            ColorPaletteApplet app = new ColorPaletteApplet();
            app.setVisible(true);
        });
    }
}