package servlets;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import beans.Manager;
import beans.Student;

public class DoCheck extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		String stunum = req.getParameter("stunum");
		String passwd = req.getParameter("passwd");
		System.out.println(passwd);
		HttpSession session = req.getSession();
		session.setAttribute("stunum", stunum);
		Student stu = new Student();
		stu.setPasswd(passwd);
		stu.setStunum(stunum);
		int result = stu.checkStu();
		session.setAttribute("result", result);
		if (result != 1) {
			req.getRequestDispatcher("failed.jsp").forward(req, resp);
		} else {
			Manager manager = new Manager();
			manager.setCc();
			req.setAttribute("classes", manager.getCc());
			req.getRequestDispatcher("success.jsp").forward(req, resp);
		}
	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		doGet(req, resp);
	}
}
