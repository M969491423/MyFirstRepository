package servlets;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import beans.People;

public class Modify extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		req.setCharacterEncoding("UTF-8");
		String households = req.getParameter("households");
		String homeType = req.getParameter("homeType");
		String homeArea = req.getParameter("homeArea");
		String roomNum = req.getParameter("roomNum");
		String name = req.getParameter("name");
		String ID = req.getParameter("ID");
		String sex = req.getParameter("sex");
		String nation = req.getParameter("nation");
		String education = req.getParameter("education");
		People p = new People();
		p.setEducation(education);
		p.setHomeArea(homeArea);
		p.setHomeType(homeType);
		p.setHouseholds(households);
		p.setID(ID);
		p.setName(name);
		p.setNation(nation);
		p.setRoomNum(roomNum);
		p.setSex(sex);
		p.deleteInfo();
		p.insertToSql();
	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		doGet(req, resp);
	}
}
