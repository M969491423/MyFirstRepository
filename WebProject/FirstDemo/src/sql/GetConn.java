package sql;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class GetConn {
	private Connection conn = null;

//	public static void main(String[] args) {
//		GetConn get = new GetConn();
//		get.getConn();
//	}

	@SuppressWarnings("finally")
	public Connection getConn() {
		String deiver = "com.mysql.cj.jdbc.Driver";
		String url = "jdbc:mysql://localhost:3306/questions?useUnicode=true"
				+ "&characterEncoding=utf8&serverTimezone=UTC&useSSL=false";
		String user = "User";
		String passwd = "xxzj541";
		try {
			Class.forName(deiver);
			conn = DriverManager.getConnection(url, user, passwd);
			if (!conn.isClosed()) {
				System.out.println("连接成功");
			} else {
				System.out.println("连接失败");
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			return this.conn;
		}
	}
}
