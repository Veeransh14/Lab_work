import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/SurveyServlet")
public class SurveyServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        int questionNumber = Integer.parseInt(request.getParameter("questionNumber"));
        String answer = request.getParameter("answer" + questionNumber);
        
        // Save the answer to a database or file
        
        // Determine the next question number
        int nextQuestionNumber = questionNumber + 1;
        
        // Redirect to the next question
        response.sendRedirect("survey.jsp?questionNumber=" + nextQuestionNumber);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        int questionNumber = Integer.parseInt(request.getParameter("questionNumber"));
        
        // Display the HTML form for the current question
        response.setContentType("text/html");
        response.getWriter().println("<!DOCTYPE html>");
        response.getWriter().println("<html lang=\"en\">");
        response.getWriter().println("<head>");
        response.getWriter().println("    <meta charset=\"UTF-8\">");
        response.getWriter().println("    <title>Online Survey</title>");
        response.getWriter().println("</head>");
        response.getWriter().println("<body>");
        response.getWriter().println("    <h1>Online Survey</h1>");
        response.getWriter().println("    <form action=\"SurveyServlet\" method=\"post\">");
        response.getWriter().println("        <input type=\"hidden\" name=\"questionNumber\" value=\"" + questionNumber + "\">");
        response.getWriter().println("        <p>Question " + questionNumber + ": What is your favorite color?</p>");
        response.getWriter().println("        <input type=\"text\" name=\"answer" + questionNumber + "\">");
        response.getWriter().println("        <br>");
        response.getWriter().println("        <input type=\"submit\" value=\"Next\">");
        response.getWriter().println("    </form>");
        response.getWriter().println("</body>");
        response.getWriter().println("</html>");
    }
}
