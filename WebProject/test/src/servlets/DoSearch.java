package servlets;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import beans.People;

public class DoSearch extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		String str = req.getParameter("string");
		List<People> peoples = null;
		People p = new People();
		peoples = p.getAllInfo(str);
		if (peoples.size() <= 0) {
			System.out.println("结果为空");
			req.setAttribute("result", -2);
			req.getRequestDispatcher("result.jsp").forward(req, resp);
		}
		req.setAttribute("infos", peoples);

		req.getRequestDispatcher("display.jsp").forward(req, resp);
	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		doGet(req, resp);
	}
}
