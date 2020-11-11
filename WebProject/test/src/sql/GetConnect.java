package sql;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class GetConnect {
	private Connection conn = null;
	private String driver = "com.mysql.cj.jdbc.Driver";
	private String url = "jdbc:mysql://localhost:3306/people?useUnicode=true"
			+ "&serverTimezone=UTC&characterEncoding=utf8&" + "useSSL=false&allowPublicKeyRetrieval=true";
	private String user = "root";
	private String passwd = "xxzj541";

	public static void main(String[] args) {
		GetConnect gc = new GetConnect();
		gc.GetConn();
	}

	@SuppressWarnings("finally")
	public Connection GetConn() {
		try {
			Class.forName(driver);
			conn = DriverManager.getConnection(url, user, passwd);
			if (!conn.isClosed()) {
				System.out.println("连接成功");
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			return conn;
		}
	}
}
