package servlets;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.SQLIntegrityConstraintViolationException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import sql.GetConn;

public class DoChoose extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		resp.setContentType("text/html");
		resp.setCharacterEncoding("UTF-8");
		PrintWriter out = resp.getWriter();
		String message = "";
		HttpSession session = req.getSession();
		String stunum = (String) session.getAttribute("stunum");
		String name = req.getParameter("name");
		String teacher = req.getParameter("teacher");
		String room = req.getParameter("room");
		Connection conn = new GetConn().getConn();
		PreparedStatement pstmt = null;
		String sql = "create table if not exists stuclass(stunum char(30),name char(50),teacher char(30),room char(30),primary key(name))";
		try {
			pstmt = conn.prepareStatement(sql);
			int result = pstmt.executeUpdate();
			if (result != -1) {
				System.out.println("表格操作成功");
				sql = "insert into stuclass(stunum,name,teacher,room) values(?,?,?,?)";
				pstmt = conn.prepareStatement(sql);
				pstmt.setString(1, stunum);
				pstmt.setString(2, name);
				pstmt.setString(3, teacher);
				pstmt.setString(4, room);
				result = pstmt.executeUpdate();
				if (result != -1) {
					System.out.println("添加成功");
					message = "添加成功";
				} else {
					System.out.println("添加失败");
				}
			} else {
				System.out.println("表格操作失败");
			}
		} catch (SQLIntegrityConstraintViolationException e) {
			message = "课程重复";
		}

		catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				pstmt.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			try {
				conn.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			out.println("<html>");
			out.println("<head>");
			out.println("<meta charset=\"UTF-8\">");
			out.println("<body style=\"text-align: center;\">");
			out.println("<h1>" + message + "</h1>");
			out.println("<input type=\"button\" value=\"确定\" onclick=\"javascript:window.location.href='index.jsp'\">");
			out.println("</body>");
			out.println("</head>");
			out.println("</html>");
		}

	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		doGet(req, resp);
	}
}
