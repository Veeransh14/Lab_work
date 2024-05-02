import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class WeatherServlet extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        response.setContentType("text/plain");
        PrintWriter out = response.getWriter();
        // Simulating fetching weather data for a location
        String location = request.getParameter("location");
        out.println("Weather Data for " + location + ": Sunny, 24°C");
    }
}


import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

public class WeatherApplet extends Applet {
    TextField input;
    TextArea output;
    Button refreshButton;

    public void init() {
        input = new TextField(20);
        add(input);
        output = new TextArea(5, 20);
        add(output);
        refreshButton = new Button("Get Weather");
        add(refreshButton);

        refreshButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                getWeather();
            }
        });
    }

    private void getWeather() {
        try {
            URL url = new URL(getCodeBase(), "weather?location=" + input.getText());
            BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
            String line = reader.readLine();
            output.setText(line);
            reader.close();
        } catch (Exception e) {
            output.setText("Failed to retrieve data.");
        }
    }
}
