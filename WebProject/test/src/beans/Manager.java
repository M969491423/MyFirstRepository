package beans;

import java.util.ArrayList;
import java.util.List;

public class Manager {
	private List<People> peoples = new ArrayList<People>();

	public List<People> getPeoples() {
		return peoples;
	}

	public void setPeoples(List<People> peoples) {
		this.peoples = peoples;
	}
}
