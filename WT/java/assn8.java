import java.io.IOException;
import java.io.PrintWriter;
import java.sql.*;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class StudentServlet extends HttpServlet {
    private String jdbcURL = "jdbc:mysql://localhost:3306/testdb";
    private String jdbcUsername = "root";
    private String jdbcPassword = "password";

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection connection = DriverManager.getConnection(jdbcURL, jdbcUsername, jdbcPassword);
            Statement statement = connection.createStatement();
            ResultSet rs = statement.executeQuery("SELECT * FROM students");

            out.println("<html><head><title>Student Mark List</title></head><body>");
            out.println("<h1>Student Mark List</h1>");
            out.println("<table border='1'><tr><th>ID</th><th>Name</th><th>Marks</th></tr>");

            while (rs.next()) {
                int id = rs.getInt("id");
                String name = rs.getString("name");
                int mark = rs.getInt("mark");

                out.println("<tr><td>" + id + "</td><td>" + name + "</td><td>" + mark + "</td></tr>");
            }
            out.println("</table></body></html>");
        } catch (Exception e) {
            e.printStackTrace();
            out.println("Error: " + e.getMessage());
        } finally {
            out.close();
        }
    }
}
