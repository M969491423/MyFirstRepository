package beans;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import sql.GetConn;

public class Student {
	private String stunum;
	private String passwd;

	public String getStunum() {
		return stunum;
	}

	public void setStunum(String stunum) {
		this.stunum = stunum;
	}

	public String getPasswd() {
		return passwd;
	}

	public void setPasswd(String passwd) {
		this.passwd = passwd;
	}

	@SuppressWarnings("finally")
	public int checkStu() {
		int result = 0;
		Connection conn = new GetConn().getConn();
		PreparedStatement prestmt = null;
		ResultSet rs = null;
		String sql = "select * from student where stunum=?";
		try {
			prestmt = conn.prepareStatement(sql);
			prestmt.setString(1, this.stunum);
			rs = prestmt.executeQuery();
			if (!rs.next()) {
				System.out.println("无此学生");
				result = -1;
			} else {
				String temp = rs.getString("passwd");
				System.out.println(temp);
				if (temp.equals(this.passwd)) {
					System.out.println("登陆成功");
					result = 1;
				} else {
					System.out.println("密码错误");
					result = 0;
				}
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				rs.close();
			} catch (SQLException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			try {
				prestmt.close();
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
			return result;
		}

	}

}
