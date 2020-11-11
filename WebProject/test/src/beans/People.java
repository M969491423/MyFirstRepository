package beans;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import sql.GetConnect;

public class People {
	private String households;
	private String homeType;
	private String homeArea;
	private String roomNum;
	private String name;
	private String ID;
	private String sex;
	private String nation;
	private String education;

	public static void main(String[] args) {
		People p = new People();
		for (People temp : p.getAllInfo("小")) {
			System.out.println(temp);
		}
	}

	@Override
	public String toString() {
		return "" + name + "  " + sex + "  " + nation + "  " + education;
	}

	public String getHouseholds() {
		return households;
	}

	public void setHouseholds(String households) {
		this.households = households;
	}

	public String getHomeType() {
		return homeType;
	}

	public void setHomeType(String homeType) {
		this.homeType = homeType;
	}

	public String getHomeArea() {
		return homeArea;
	}

	public void setHomeArea(String homeArea) {
		this.homeArea = homeArea;
	}

	public String getRoomNum() {
		return roomNum;
	}

	public void setRoomNum(String roomNum) {
		this.roomNum = roomNum;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getID() {
		return ID;
	}

	public void setID(String iD) {
		ID = iD;
	}

	public String getSex() {
		return sex;
	}

	public void setSex(String sex) {
		this.sex = sex;
	}

	public String getNation() {
		return nation;
	}

	public void setNation(String nation) {
		this.nation = nation;
	}

	public String getEducation() {
		return education;
	}

	public void setEducation(String education) {
		this.education = education;
	}

	public void display() {
		System.out.println(name);
		System.out.println(sex);
		System.out.println(nation);
		System.out.println(education);
	}

	public List<People> getAllInfo(String str) {
		str = "%" + str + "%";
		List<People> peoples = new ArrayList<People>();
		Connection conn = new GetConnect().GetConn();
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		if (conn == null) {
			System.out.println("连接失败");
			return null;
		} else {
			System.out.println("连接成功");
			String sql = "select * from information where name like ? or sex like ? or nation like ? or education like ?;";
			try {
				pstmt = conn.prepareStatement(sql);
				pstmt.setString(1, str);
				pstmt.setString(2, str);
				pstmt.setString(3, str);
				pstmt.setString(4, str);
				rs = pstmt.executeQuery();
				while (rs.next()) {
					People temp = new People();
					String name = rs.getString("name");
					String sex = rs.getString("sex");
					String nation = rs.getString("nation");
					String education = rs.getString("education");
					temp.setName(name);
					temp.setNation(nation);
					temp.setSex(sex);
					temp.setEducation(education);
					peoples.add(temp);
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} finally {
				try {
					rs.close();
					pstmt.close();
					conn.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
		return peoples;
	}

	public boolean insertToSql() {
		boolean b = true;
		Connection conn = new GetConnect().GetConn();
		PreparedStatement pstmt = null;
		String sql;
		if (conn == null) {
			System.out.println("连接失败");
		} else {
			sql = "insert into information(households,hometype,homearea,roomnum,name,id"
					+ ",sex,nation,education) values(?,?,?,?,?,?,?,?,?)";
			try {
				pstmt = conn.prepareStatement(sql);
				pstmt.setString(1, households);
				pstmt.setString(2, homeType);
				pstmt.setString(3, homeArea);
				pstmt.setString(4, roomNum);
				pstmt.setString(5, name);
				pstmt.setString(6, ID);
				pstmt.setString(7, String.valueOf(sex));
				pstmt.setString(8, nation);
				pstmt.setString(9, education);
				int result = pstmt.executeUpdate();
				if (result == -1) {
					b = false;
					System.out.println("添加失败");
				} else {
					System.out.println("添加成功");
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} finally {
				try {
					pstmt.close();
					conn.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
		return b;
	}

	public boolean getInfo() {
		Connection conn = new GetConnect().GetConn();
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		String sql;
		boolean b = false;
		if (conn == null) {
			System.out.println("连接失败");
		} else {
			sql = "select * from information where name='" + name + "';";
			try {
				pstmt = conn.prepareStatement(sql);
				rs = pstmt.executeQuery();
				if (rs.next()) {
					b = true;
					System.out.println("查找成功");
					sex = rs.getString("sex");
					nation = rs.getString("nation");
					education = rs.getString("education");
				} else {
					System.out.println("无此人");
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} finally {
				try {
					rs.close();
					pstmt.close();
					conn.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}

		}
		return b;
	}

	public void deleteInfo() {
		Connection conn = new GetConnect().GetConn();
		PreparedStatement pstmt = null;
		String sql;
		if (conn != null) {
			sql = "delete from information where name=?";
			try {
				pstmt = conn.prepareStatement(sql);
				pstmt.setString(1, name);
				int result = pstmt.executeUpdate();
				if (result != -1) {
					System.out.println("删除成功");
				} else {
					System.out.println("删除失败");
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} finally {
				try {
					pstmt.close();
					conn.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}
}
