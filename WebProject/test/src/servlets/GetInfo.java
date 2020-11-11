package servlets;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import beans.People;

public class GetInfo extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		String name = req.getParameter("name");
		HttpSession session = req.getSession();
		String str = (String) session.getAttribute("type");
		int type;
		if (str == null) {
			str = req.getParameter("type");
		}
		type = Integer.valueOf(str);

		People p = new People();
		p.setName(name);
		if (p.getInfo()) {
			p.display();
			req.setAttribute("info", p);
			if (type == 1) {
				req.getRequestDispatcher("modify.jsp").forward(req, resp);
			} else if (type == 2) {
				req.getRequestDispatcher("delete.jsp").forward(req, resp);
			} else if (type == 3) {
				req.getRequestDispatcher("information.jsp").forward(req, resp);
			}
		} else {
			req.setAttribute("result", -2);
			req.getRequestDispatcher("result.jsp").forward(req, resp);
		}
	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		doGet(req, resp);
	}
}
