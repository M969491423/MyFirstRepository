package beans;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import sql.GetConn;

public class Manager {
	private List<ChooseClass> cc = new ArrayList<>();

	public void setCc() {
		ChooseClass temp = new ChooseClass();
		Connection conn = new GetConn().getConn();
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		String sql = "select * from classes";
		try {
			pstmt = conn.prepareStatement(sql);
			rs = pstmt.executeQuery();
			while (rs.next()) {
				temp.setName(rs.getString("name"));
				temp.setRoom(rs.getString("room"));
				temp.setTeacher(rs.getString("teacher"));
				cc.add(temp);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				rs.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
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
		}
	}

	public List<ChooseClass> getCc() {
		return this.cc;
	}
}
