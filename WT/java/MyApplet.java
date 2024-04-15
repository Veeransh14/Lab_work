import java.applet.Applet;
import java.awt.*;
import java.net.*;
import java.io.*;

public class MyApplet extends Applet {
    TextArea outputArea;

    public void init() {
        this.setLayout(new BorderLayout());
        Button button = new Button("Fetch Data");
        outputArea = new TextArea(5, 40);
        add(button, BorderLayout.NORTH);
        add(outputArea, BorderLayout.CENTER);
        button.addActionListener(e -> fetchData());
    }

    private void fetchData() {
        try {
            URL url = new URL(getCodeBase(), "MyServlet");
            URLConnection conn = url.openConnection();
            conn.setDoInput(true);
            BufferedReader reader = new BufferedReader(new InputStreamReader(conn.getInputStream()));
            String line;
            while ((line = reader.readLine()) != null) {
                outputArea.append(line + "\n");
            }
            reader.close();
        } catch (Exception e) {
            outputArea.append("Error: " + e.getMessage());
        }
    }
}
