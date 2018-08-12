CREATE TABLE fileAccess(id BIGINT, 
						hash VARCHAR(64), 
						originalFileName VARCHAR(260));
CREATE TABLE properties(id BIGINT, 
						name VARCHAR(128));
CREATE TABLE file_property_match(fileAccess_id BIGINT REFERENCES fileAccess(id), 
								prop_id BIGINT REFERENCES properties(id), 
								specific_property VARCHAR(1024));

CREATE TABLE notes(	id BIGINT,
					note VARCHAR(2048));
CREATE TABLE note_property_match(	prop_id BIGINT REFERENCES properties(id),
									note_id BIGINT REFERENCES notes(id)
									);